#include <iostream>

using namespace std;
#define SIZE        10 + 1

int root[SIZE];
int depth[SIZE];

void init(int n) {
    for(int i = 0; i < n; i++) {
        root[i] = i;
    }
}

int find(int x) {
    if(root[x] == x) return x;
    return root[x] = find(root[x]);
}

void merge(int x, int y) {
    x = find(x); y = find(y);
    
    if(depth[x] >= depth[y]) {
        root[y] = x; depth[x] += depth[y];
    }
    else { // depth[x] < depth[y]
        root[x] = y; depth[y] += depth[x];
    }
}

int result(int n, int m) {
    int x, y;
    for(int cnt = 1; cnt <= m; cnt++) {
        cin >> x >> y;
        merge(x, y);
        if(find(x) == find(y))
            return cnt;
    }
    
    return 0;
}

int main( ) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    int n, m;
    int res;
    cin >> n >> m;
    res = result(n, m);
    cout << res << '\n';
    
    return 0;
}

