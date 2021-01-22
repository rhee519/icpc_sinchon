#include <iostream>
#include <algorithm>

using namespace std;
#define VER_NUM         10 + 1
#define EDGE_NUM        10 + 1

struct edge{
    int cost; // red : 0, blue : 1
    int from, to;
    
    bool operator<(const edge &other) const {
        return cost < other.cost;
    }
};

edge e[EDGE_NUM];
int root[VER_NUM]; // union-find

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

int minCost(int n, int m) {
    // e is already sorted in cost-nondecreasing order
    int cost = 0;
    int cnt = 0;
    for(int i = 0; i < m; i++) {
        
    }
    
    return cost;
}

int maxCost(int n, int m) {
    // e is already sorted in cost-nondecreasing order
    int cost = 0;
    
    return cost;
}

int main( ) {
    int n, m, k;
    char ch;
    while(true) {
        cin >> n >> m >> k;
        if(n == 0 && m == 0 && k == 0) break;
        
        for(int i = 0; i < m; i++) { // edge input
            cin >> ch >> e[i].from >> e[i].to;
            if(ch == 'R') e[i].cost = 0;
            else if(ch == 'B') e[i].cost = 1;
        }
        
        sort(e, e+m); // sort in cost-nondecreasing order
        int minC = minCost(n, m);
        int maxC = maxCost(n, m);
        int res;
        
        if(minC <= k && k <= maxC) res = 1;
        else res = 0;
        
        cout << res << '\n';
    }
    return 0;
}