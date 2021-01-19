#include <iostream>

using namespace std;

unsigned dp[32][32];
unsigned com[32][32]; // combination, com[n][r] = nCr (n >= r)
int res[32];    // target number in binary format (ex. res[0:4] = {1, 1, 0, 0, 1} (10011))

void init(int n) {
    com[0][0] = 1;
    
    for(int i = 1; i <= n; i++) {
        com[i][0] = com[i][i] = 1;
        for(int j = 1; j < i; j++) {
            com[i][j] = com[i-1][j-1] + com[i-1][j];
        }
    }
    
    // dp table
    // dp[n][i] == # of numbers within n bits & less than or equal to i-1's
    //          == nC0 + nC1 + ... + nCi
    //          == com[n][0] + ... + com[n][i]
    // dp[3][1] == 4 (0, 1, 10, 100)
    // dp[4][2] == 11 (0, 1, 10, 11, 100, 101, 110, 1000, 1001, 1010, 1100)
    // O(n^2)
    for(int k = 1; k <= n; k++) {
        dp[k][0] = com[k][0]; // == 1
        for(int m = 1; m <= k; m++) {
            dp[k][m] = dp[k][m-1] + com[k][m];
        }
        for(int m = k+1; m <= n; m++) {
            dp[k][m] = dp[k][k];
        }
    }
}

int getNum(int n, int l, unsigned idx) {
    if(idx > dp[n][l]) return -1;   // out-of-index
    if(idx == 1) return 1;          // res = 0
    if(idx == 2) {
        res[0] = 1; return 1;       // res = 1
    }
    
    
    int bit = 0;  // # of bits of target number
    while(dp[bit][l] < idx) bit++;
    
    
    // fill res[] (target number)
    // in binary format
    res[bit-1] = 1;
    getNum(bit-1, l-1, idx-dp[bit-1][l]);
    return bit;
}

int main( ) {
    freopen("input.txt", "r", stdin);
    
    int n, l;
    unsigned idx; // 1 <= n <= 31
    int bit;
    
    cin >> n >> l >> idx;
    
    init(n);
    bit = getNum(n, l, idx);
    for(int i = n-1; i >= 0; i--) {
        cout << res[i];
    }
    cout << '\n';
    
    return 0;
}
