#include <iostream>
#include <algorithm>

using namespace std;
#define VERTEX_NUM      10 + 1
#define EDGE_NUM        15 + 1

struct edge{
    int start, end, cost;
    bool operator< (const edge &other) const {
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

int minCostByKruskal(int n, int m, int k) {
    int minCost = 0;
    
    return minCost;
}

int main( ) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    int n, m, k;
    int plant;   // not used
    int minCost;
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++) { // plant input
        cin >> plant;
    }
    for(int i = 0; i < m; i++) { // edge input
        edge e; cin >> e.start >> e.end >> e.cost;
    }
    
    minCost = minCostByKruskal(n, m, k);
    cout << minCost << '\n';
    
    return 0;
}
