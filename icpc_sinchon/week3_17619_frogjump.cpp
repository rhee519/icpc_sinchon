#include <iostream>
#include <algorithm>

using namespace std;
#define SIZE        100'000 + 1

struct line{
    int idx;
    int x1, x2;
    
    bool operator<(const line &other) const{
        if(x1 == other.x1) return (x2 < other.x2);
        return x1 < other.x1;
    }
};

int parent[SIZE];
line arr[SIZE];

int find(int x) {
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void group(int x, int y) {
    x = find(x); y = find(y);
    parent[y] = x;
}

void connect(int n) {
    sort(arr+1, arr+n+1); // sort arr[1~n] in non-decreasing order by x1 & x2
    parent[arr[1].idx] = arr[1].idx;
    
    for(int i = 2; i <= n; i++) {
        parent[arr[i].idx] = arr[i].idx;
        if(arr[i-1].x2 >= arr[i].x1) { // connected
            group(arr[i-1].idx, arr[i].idx);
            arr[i].x2 = max(arr[i-1].x2, arr[i].x2); // update rightmost point
        }
    }
}

bool canJump(int idx1, int idx2) {
    return find(idx1) == find(idx2);
}

int main( ) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    
    int n, q;
    cin >> n >> q;
    
    for(int i = 1; i <= n; i++) {
        int y; // not used
        cin >> arr[i].x1 >> arr[i].x2 >> y;
        arr[i].idx = i;
    }
    
    connect(n);
    
    for(int i = 0; i < q; i++) {
        int idx1, idx2;
        cin >> idx1 >> idx2;
        if(canJump(idx1, idx2))
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }
    
    return 0;
}
