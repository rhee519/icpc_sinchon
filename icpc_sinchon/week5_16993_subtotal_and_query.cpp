#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;
#define MAX_SIZE        11 + 1

struct segment {
    int Lmax, Rmax, Mmax;
} seg[4*MAX_SIZE];

int input[MAX_SIZE], acc[MAX_SIZE];
// acc[n] = input[1] + ... + input[n]
// acc[m] - acc[n-1] = input[n] + ... + input[m]

segment init(int now, int start, int end) {
    if(start == end) {
        return seg[now] = {input[start], input[start], input[start]};
    }
    
    int Ltail = input[start], Rtail = input[end];
    int mid = (start + end)/2;
    // Ltail : max sum including input[start]
    // Rtail : max sum including input[end]
    // mid : mid idx
    
    init(now*2, start, mid);    // left child node
    init(now*2+1, mid+1, end);  // right child node
    
    for(int i = start+1; i <= end; i++) {
        Ltail += input[i];
        
    }
    for(int i = end-1; i >= start; i--) {
        if(input[i] < 0) break;
        Rtail += input[i];
    }
    
    seg[now].Mmax = max({seg[now].Lmax, seg[now].Rmax, seg[now*2].Rmax + seg[now*2+1].Lmax});
    return seg[now];
}

int main( ) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    
    int n, q;
    cin >> n; // input array size
    for(int i = 1; i <= n; i++) {
        cin >> input[i]; acc[i] = acc[i-1] + input[i];
    }
    
    init(1, 1, n);
    
    cin >> q; // # of queries
    for(int i = 1; i <= q; i++) {
        
    }
    
    
    return 0;
}
