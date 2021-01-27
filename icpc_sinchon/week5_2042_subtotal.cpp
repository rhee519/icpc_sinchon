#include <iostream>
#include <algorithm>

using namespace std;

const int ST_SIZE = 1<<10;

int seg[ST_SIZE * 2];

void build( ) {
    for(int i = ST_SIZE-1; i >= 1; i--) {
        seg[i] = seg[i*2] + seg[i*2+1];
    }
}

void update(int idx, int val) {
    int n = ST_SIZE + idx; // idx'th leaf node on Seg Tree
    seg[n] = val; // update value
    
    for(n /= 2; n >= 1; n /= 2) {
        
    }
}

int main( ) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    
    
    
    return 0;
}
