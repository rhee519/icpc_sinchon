#include <iostream>
#include <math.h>
#include <cstring>

#define WNUM        1000 + 1
#define INF         1E9

using namespace std;

typedef struct {
    int y, x;
} pos;

pos inc[WNUM];
int dp[WNUM][WNUM];
// dp[i][j] : min cost of p1 @ inc[i] && p2 @ inc[j]
int path[WNUM];


inline int getDist(pos from, pos to) {
    return abs(from.y - to.y) + abs(from.x - to.x);
}

int getMinDist(int n, int w, int i, int j) {
    // recursive method
    // dp[i][j] := min cost from p1@inc[i], p2@inc[j]
    
    if(i == w || j == w) // finished
        return 0;
    
    if(dp[i][j] != -1) return dp[i][j];
    
    int next = max(i, j) + 1;   // # of next incident
    int d1, d2;
    // d1 : dist between p1 & inc[next]
    // d2 : dist between p2 & inc[next]
    
    if(i == 0)
        d1 = getDist({1, 1}, inc[next]);
    else
        d1 = getDist(inc[i], inc[next]);
    
    if(j == 0)
        d2 = getDist({n, n}, inc[next]);
    else
        d2 = getDist(inc[j], inc[next]);
    
    d1 += getMinDist(n, w, next, j);
    d2 += getMinDist(n, w, i, next);
    
    if(d1 < d2) {
        dp[i][j] = d1;
        path[next-1] = 1;
    }
    else {
        dp[i][j] = d2;
        path[next-1] = 2;
    }
    return dp[i][j];
}

int printPath(int n, int w, int i, int j) {
    for(int i = 0; i < w; i++) {
        cout << path[i] << '\n';
    }
    
    /*
    if(i == w || j == w)
        return 0;
    
    int next = max(i, j) + 1;
    int d1, d2;
    
    if(i == 0)
        d1 = getDist({1, 1}, inc[next]);
    else
        d1 = getDist(inc[i], inc[next]);
    
    if(j == 0)
        d2 = getDist({n, n}, inc[next]);
    else
        d2 = getDist(inc[j], inc[next]);
    
    d1 += dp[next][j];
    d2 += dp[i][next];
    
    if(d1 <= d2) {
        cout << "1\n";
        printPath(n, w, next, j);
    }
    else {
        cout << "2\n";
        printPath(n, w, i, next);
    }
    
    
    return 0;
     */
    
    return 0;
}

int main( ) {
    freopen("input.txt", "r", stdin);
    
    int n, w;
    int minDist;
    
    cin >> n >> w;
    for(int i = 1; i <= w; i++) {
        cin >> inc[i].y >> inc[i].x;
    }
    
    memset(dp, -1, sizeof(dp));
    minDist = getMinDist(n, w, 0, 0);
    cout << minDist << '\n';
    printPath(n, w, 0, 0);
    
    return 0;
}
