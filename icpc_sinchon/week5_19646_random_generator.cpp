#include <iostream>
//#include <algorithm>

using namespace std;
#define SIZE    200'000 + 1

int seg[4*SIZE];
int arr[SIZE];
int w[SIZE];

int init(int now, int start, int end) {
    if(start == end) {
        return seg[now] = w[start];
    }
    
    int mid = (start+end)/2;
    init(now*2, start, mid); init(now*2+1, mid+1, end);
    
    return seg[now] = seg[now*2] + seg[now*2+1];
}

int find(int now, int start, int end, int val) {
    // find idx'th num in arr
    if(start == end) // target found
        return start;
    int mid = (start+end)/2;
    if(seg[now*2] < val) { // target is in right child node
        return find(now*2+1, mid+1, end, val - seg[now*2]);
    }
    // target is in left child node
    return find(now*2, start, mid, val);
}

int update(int now, int start, int end, int val) {
    // erase all target value from seg tree
    if(val < start || end < val) // out of boundary
        return seg[now];
    if(start == end)    // target found
        return seg[now] = 0;
    
    int mid = (start+end)/2;
    update(now*2, start, mid, val);
    update(now*2+1, mid+1, end, val);
    return seg[now] = seg[now*2] + seg[now*2+1];
}

int main( ) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    init(1, 1, n);
    for(int i = 1; i <= n; i++) {
        int val; cin >> val;        // input p_i
        val = find(1, 1, n, val);   // find p_i'th value
        cout << val << ' ';
        update(1, 1, n, val);       // erase value from arr
    }
    
    cout << '\n';
    
    return 0;
}
