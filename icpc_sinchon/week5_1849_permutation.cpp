#include <iostream>
#include <algorithm>

using namespace std;

const int ST = 1<<17;

int seg[ST*2];

void build( ) {
    for(int i = ST-1; i >= 1; i--) {
        seg[i] = seg[i*2] + seg[i*2+1];
    }
}

void update(int idx, int val) {
    int i = ST + idx;
}

int main( ) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    
    return 0;
}
