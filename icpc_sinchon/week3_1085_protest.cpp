#include <iostream>
#include <algorithm>
#include <queue>
#include <limits.h>

using namespace std;
#define VER_NUM     1'000 + 1
#define EDGE_NUM    50'000 + 1

struct edge{
    int from, to;
    int width;
    bool operator< (const edge &other) const {
        return width < other.width;
    }
};

vector<pair<int, int>> v[VER_NUM]; // <counterpart_vertex, width>
bool visited[VER_NUM];

int prim(int src, int des, int p) {
    int min_width = INT_MAX;
    priority_queue<edge> pq;
    visited[src] = true;
    for(auto iter : v[src]) {
        edge e = {src, iter.first, iter.second};
        pq.push(e);
    }
    
    for(int i = 0; i < p-1; i++) { // MST includes at most n-1 edges
        edge e;
        while(!pq.empty()) {
            e = pq.top(); pq.pop();
            if(!visited[e.to]) break; // ignore visited edges
        }
        // include e into MST
        int next = e.to;
        visited[next] = true;
        if(min_width > e.width) min_width = e.width; // pq is sorted in width-nonincreasing order
        if(next == des) break; // arrived at destination
        
        // next incident edges
        for(auto iter : v[next]) {
            edge f = {next, iter.first, iter.second}; pq.push(f);
        }
    }
    
    return min_width;
}

int main( ) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    int p, w;
    int src, des;
    int min_width;
    cin >> p >> w;
    cin >> src >> des;
    for(int i = 0; i < w; i++) {
        int from, to, width;
        cin >> from >> to >> width;
        v[from].push_back(make_pair(to, width));
        v[to].push_back(make_pair(from, width));
    }
    
    min_width = prim(src, des, p);
    cout << min_width << '\n';
    
    return 0;
}
