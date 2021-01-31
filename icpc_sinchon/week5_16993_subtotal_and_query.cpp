#include <iostream>
#include <algorithm>

using namespace std;
#define MAX_SIZE        100'000 + 1

struct segment {
    int Lmax, Rmax, Mmax;
} seg[4*MAX_SIZE];

int input[MAX_SIZE], acc[MAX_SIZE];
// acc[n] = input[1] + ... + input[n]
// acc[m] - acc[n-1] = input[n] + ... + input[m]

int main( ) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> input[i]; acc[i] = acc[i-1] + input[i];
    }
    
    return 0;
}
