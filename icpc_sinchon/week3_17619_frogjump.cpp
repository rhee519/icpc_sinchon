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
    sort(arr+1, arr+n+1); // sort arr[1~n] in non-decreasing order by x1 & x2
    
    parent[arr[1].idx] = 1;
    for(int i = 2; i <= n; i++) {
        if(arr[i-1].x2 >= arr[i].x1) // connected
            parent[arr[i].idx] = parent[arr[i-1].idx];
        else // not connected
            parent[arr[i].idx] = parent[arr[i-1].idx] + 1;
    }
}

bool canJump(int idx1, int idx2) {
    return parent[idx1] == parent[idx2];
}

int main( ) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    
    int n, q;
    cin >> n >> q;
    
    for(int i = 1; i <= n; i++) {
        int y; // not used
        cin >> arr[i].x1 >> arr[i].x2 >> y;
        arr[i].idx = i;
    }
    
    connect(n);
    
    for(int i = 0; i < q; i++) {
        int idx1, idx2;
        cin >> idx1 >> idx2;
        if(canJump(idx1, idx2))
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }
    
    return 0;
}
