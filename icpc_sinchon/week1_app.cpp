#include <iostream>

#define SIZE        100
#define MAX_COST    100
using namespace std;

inline int max(int a, int b) {
    return (a > b)? a : b;
}

int mem[SIZE+1];
int cost[SIZE+1];
int dp[SIZE+1][MAX_COST*SIZE+1];
// dp[i][j] := maximum profit(memory) from 1 ~ i th apps with cost (less than j)

int getMinCost(int n, int m, int total_cost) {
    // initialize
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= total_cost; j++) {
            if(cost[i] > j) { // cannot contain i th app
                dp[i][j] = dp[i-1][j];
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-cost[i]] + mem[i]);
            }
        }
    }
    
    // find the minimum cost
    for(int j = 0; j <= total_cost; j++) {
        for(int i = 1; i <= n; i++) {
            if(dp[i][j] >= m) return j;
        }
    }
    
    // error
    return -1;
}

int main(int argc, const char * argv[]) {
    freopen("input.txt", "r", stdin);
    
    int n, m;
    int total_cost = 0;
    int min_cost;
    
    // input
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> mem[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> cost[i];
        total_cost += cost[i];
    }
    
    // dynamic programming
    min_cost = getMinCost(n, m, total_cost);
    cout << min_cost << "\n";
    
    return 0;
}
