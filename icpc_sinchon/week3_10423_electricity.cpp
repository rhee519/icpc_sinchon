#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
#define VERTEX_NUM      1'000 + 1
#define EDGE_NUM        100'000 + 1

struct edge{
    int start, end, cost;
    bool operator< (const edge &other) const {
        return cost > other.cost; // need to construct min-heap
    }
};

vector<pair<int, int>> v[VERTEX_NUM];
vector<int> plant;
bool planted[VERTEX_NUM];

int minCostByPrim(int n, int m, int k) {
    int minCost = 0;
    priority_queue<edge> pq;
    
    // initialize
    for(int p : plant) { // plants
        planted[p] = true;
        for(auto iter : v[p]) {
            edge e = {p, iter.first, iter.second}; pq.push(e);
        }
    }
    
    // prim's algorithm
    // construct MST (but only includes (n-k) edges)
    for(int i = 0; i < n-k; i++) {
        edge e;
        while(!pq.empty()) {
            e = pq.top(); pq.pop();
            if(!planted[e.end]) break;
        }
        // connect unplanted vertex
        planted[e.end] = true; minCost += e.cost;
        // next vertices
        for(auto iter : v[e.end]) {
            edge f = {e.end, iter.first, iter.second}; pq.push(f);
        }
    }
    
    return minCost;
}

int main( ) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    
    int n, m, k; // k <= n
    int p;
    int minCost;
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++) { // plant input
        cin >> p; plant.push_back(p);
    }
    for(int i = 0; i < m; i++) { // edge input
        int start, end, cost; cin >> start >> end >> cost;
        v[start].push_back(make_pair(end, cost));
        v[end].push_back(make_pair(start, cost));
    }
    
    minCost = minCostByPrim(n, m, k);
    cout << minCost << '\n';
    
    return 0;
}
