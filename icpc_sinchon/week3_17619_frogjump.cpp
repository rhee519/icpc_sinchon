#include <iostream>
#include <algorithm>

using namespace std;
#define SIZE        10 + 1

struct line{
    int idx;
    int x1, x2;
    
    bool operator<(const line &other) const{
        if(x1 == other.x1) return (x1 < x2);
        return x1 < other.x1;
    }
};

int parent[SIZE];
line arr[SIZE];

void connect(int n) {
    
}

bool canJump(int n, int idx1, int idx2) {
    
    return false;
}

int main( ) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        int y;
        cin >> arr[i].x1 >> arr[i].x2 >> y;
        arr[i].idx = i;
    }
    
    
    
    return 0;
}
