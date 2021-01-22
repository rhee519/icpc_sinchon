#include <iostream>
#include <algorithm>

using namespace std;

#define VERTEX_NUM      1000 + 1
#define EDGE_NUM        100'000 + 1

struct edge{
    int from, to;
    int cost;
    
    bool operator<(const edge &other) const {
        return cost < other.cost;
    }
};

int root[VERTEX_NUM];
edge e[EDGE_NUM];

void init(int n) {
    for(int i = 1; i <= n; i++) {
        root[i] = i;
    }
}

int find(int x) {
    if(root[x] == x) return x;
    return root[x] = find(root[x]);
}

void merge(int x, int y) {
    x = find(x); y = find(y);
    root[y] = x;
}

int costByKruskal(int n, int m) {
    int cost = 0;
    int cnt = 0;
    sort(e, e+m); // sort in cost-nondecreasing order
    
    for(int i = 0; i < m; i++) {
        int from = find(e[i].from);
        int to = find(e[i].to);
        if(from == to) continue; // do not include in MST
        merge(from, to); cnt++; cost += e[i].cost;
        if(cnt == n-1) break;
    }
    
    return cost;
}

int main( ) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    
    int n, m;
    int cost;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> e[i].from >> e[i].to >> e[i].cost;
    }
    
    init(n);
    cost = costByKruskal(n, m);
    cout << cost << '\n';
    
    return 0;
}
