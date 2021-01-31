#include <iostream>
//#include <algorithm>

using namespace std;
#define SIZE    10 + 1

int seg[4*SIZE];
bool check[SIZE];

void init(int now, int start, int end) {
    if(start == end) {
        seg[now] = 1;
        return;
    }
    
    int mid = (start+end)/2;
    init(now*2, start, mid); init(now*2+1, mid+1, end);
    seg[now] = seg[now*2] + seg[now*2+1];
}

int main( ) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    
    return 0;
}
