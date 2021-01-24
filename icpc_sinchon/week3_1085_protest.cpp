#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
#define VER_NUM     10 + 1
#define EDGE_NUM    20 + 1

struct edge{
    int from, to;
    int width;
    bool operator< (const edge &other) const {
        return width > other.width;
    }
};

vector<pair<int, int>> v[VER_NUM]; // <counterpart_vertex, width>
bool visited[VER_NUM];

int prim(int src, int des) {
    int max_width;
    
    
    return max_width;
}

int main( ) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    int p, w;
    int src, des;
    int max_width;
    cin >> p >> w;
    cin >> src >> des;
    
    max_width = prim(src, des);
    cout << max_width << '\n';
    
    return 0;
}
