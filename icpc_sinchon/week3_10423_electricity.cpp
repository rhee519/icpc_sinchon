#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
#define VERTEX_NUM      10 + 1
#define EDGE_NUM        15 + 1

struct edge{
    int start, end, cost;
    bool operator< (const edge &other) const {
        return cost < other.cost;
    }
};

bool planted[VERTEX_NUM];

int main( ) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    
    int n, m, k; // k <= n
    int plant;   // not used
    int minCost;
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++) { // plant input
        cin >> plant;
    }
    for(int i = 0; i < m; i++) { // edge input
        
    }
    
    
    cout << minCost << '\n';
    
    return 0;
}
