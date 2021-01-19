#include <iostream>
#include <vector>

using namespace std;

int dp[51][51][51];
// dp[root][least_child_idx][num]
// solution == dp[1][k] + dp[2][k] + ... + dp[n-k+1][k]
vector<int> v[51];
// adj list

int count(int n, int k) {
    int cnt = 0;
    // initialize
    for(int root = 1; root < n; root++) {
        for(int child = root+1; child <= n; child++) {
            dp[root][child][1] = 1;
        }
    }
    
    // dp table
    for(int num = 2; num <= k; num++) {
        for(int root = n-1; root >= 1; root--) {
            for(int child = n; child > root; child--) {
                for(int m = 0; m <= num; m++) {
                    dp[root][child][num] += dp[root][child][m] + dp[root][child][num-m];
                }
            }
        }
    }
    
    // count
    for(int root = 1; root <= n-k+1; root++) {
        cnt += dp[root][root+1][k];
    }
    
    return cnt;
}

int main( ) {
    freopen("input.txt", "r", stdin);
    
    int n, k;
    int cnt;
    
    cin >> n >> k;
    for(int i = 1; i < n; i++) { // repeat n-1 times (n-1 edges)
        int from, to;
        cin >> from >> to;  // from != to
        if(from < to) v[from].push_back(to);
        else v[to].push_back(from);
    }
    
    cnt = count(n, k);
    cout << cnt << '\n';
    
    return 0;
}
