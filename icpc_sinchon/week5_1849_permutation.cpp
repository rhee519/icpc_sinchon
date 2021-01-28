#include <iostream>
#include <algorithm>

using namespace std;
#define MAX_SIZE        1'000'000 + 1
int seg[MAX_SIZE * 4];
int p[MAX_SIZE];

int update(int pos, int val, int node, int left, int right) {
    // update arr[pos] to val
    // && return seg[node] == sum of arr[left] ~ arr[right]
    
    if(pos < left || right < pos)
        return seg[node];
    
    // left <= pos <= right
    if(left == right)
        return seg[node] = val;
    int mid = (left + right)/2;
    return seg[node] = update(pos, val, node*2, left, mid) + update(pos, val, node*2+1, mid+1, right);
}

int query(int val, int node, int left, int right) {
    // return pos of val
    if(left == right) return left;
    
    int mid = (left + right)/2;
    if(seg[node*2] >= val) // left <= pos <= mid
        return query(val, node*2, left, mid);
    // mid+1 <= pos <= right
    return query(val-seg[node*2], node*2+1, mid+1, right);
}

int main( ) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        update(i, 1, 1, 1, n);
    }
    
    for(int i = 1; i <= n; i++) {
        int pos; cin >> pos;
        int q = query(pos+1, 1, 1, n);
        p[q] = i;
        update(q, 0, 1, 1, n);
    }
    
    // print
    for(int i = 1; i <= n; i++) {
        cout << p[i] << '\n';
    }
    
    return 0;
}

