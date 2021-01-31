#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;
#define MAX_SIZE        100'000 + 1

struct segment {
    long long Lmax, Rmax, Mmax;
} seg[4*MAX_SIZE];

long long input[MAX_SIZE], acc[MAX_SIZE];
// acc[n] = input[1] + ... + input[n]
// acc[m] - acc[n-1] = input[n] + ... + input[m]

segment init(int now, int start, int end) {
    if(start == end) {
        return seg[now] = {input[start], input[start], input[start]};
    }
    
    int Ltail = 0, Rtail = 0;
    int mid = (start + end)/2;
    // Ltail : max sum including input[start]
    // Rtail : max sum including input[end]
    // mid : mid idx
    
    init(now*2, start, mid);    // left child node
    init(now*2+1, mid+1, end);  // right child node
    
    seg[now].Lmax = seg[now].Rmax = INT_MIN;
    for(int i = start; i <= end; i++) {
        Ltail += input[i];
        if(seg[now].Lmax < Ltail) seg[now].Lmax = Ltail;
    }
    for(int i = end; i >= start; i--) {
        Rtail += input[i];
        if(seg[now].Rmax < Rtail) seg[now].Rmax = Rtail;
    }
    
    seg[now].Mmax = max({seg[now*2].Mmax, seg[now*2+1].Mmax, seg[now*2].Rmax + seg[now*2+1].Lmax});
    return seg[now];
}

segment query(int now, int start, int end, int l, int r) {
    if(l > end || r < start) return {INT_MIN, INT_MIN, INT_MIN};    // out-of-bounds
    if(l <= start && end <= r) return seg[now];
    
    int mid = (start + end)/2;
    segment ret, lc, rc;
    lc = query(now*2, start, mid, l, r);
    rc = query(now*2+1, mid+1, end, l, r);
    ret.Lmax = max(lc.Lmax, acc[mid] - acc[start-1] + rc.Lmax);
    ret.Rmax = max(lc.Rmax + acc[end] - acc[mid], rc.Rmax);
    ret.Mmax = max({lc.Mmax, rc.Mmax, lc.Rmax + rc.Lmax});
    
    return ret;
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
        int l, r; cin >> l >> r;
        cout << query(1, 1, n, l, r).Mmax << '\n';
    }
    
    
    return 0;
}
