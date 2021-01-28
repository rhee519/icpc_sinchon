#include <iostream>
#include <algorithm>

using namespace std;

const int ST_SIZE = 1<<20;

long long seg[ST_SIZE * 2];
// seg[1] = input[1] + ... + input[n]
// seg[2] = input[1] + ... + input[n/2]
// seg[3] = input[n/2+1] + ... + input[n]
// seg[ST_SIZE+idx] = input[idx]

void build( ) {
    for(int i = ST_SIZE-1; i >= 1; i--) {
        seg[i] = seg[i*2] + seg[i*2+1];
    }
}

void update(int idx, long long val) {
    int n = ST_SIZE + idx; // idx'th leaf node on Seg Tree
    seg[n] = val; // update value
    
    // update only editted subtotal
    for(n /= 2; n >= 1; n /= 2) {
        seg[n] = seg[n*2] + seg[n*2+1];
    }
}

long long query(int n, int nl, int nr, int l, int r) {
    if(l > nr || r < nl) // out of bound
        return 0;
    if(l <= nl && nr <= r) // seg[n] is included in query bound (l ~ r)
        return seg[n];
    int mid = (nl + nr)/2;
    return query(n*2, nl, mid, l, r) + query(n*2+1, mid+1, nr, l, r);
}

int main( ) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        cin >> seg[ST_SIZE + i];
    }
    
    // initialize
    build();
    
    // query input
    for(int i = 0; i < m+k; i++) {
        int q;
        long long x, y;
        cin >> q >> x >> y;
        
        switch (q) {
            case 1:
                update((int)x, y);
                break;
            case 2:
                cout << query(1, 0, ST_SIZE-1, (int)x, (int)y) << '\n';
                break;
        }
    }
    
    return 0;
}
