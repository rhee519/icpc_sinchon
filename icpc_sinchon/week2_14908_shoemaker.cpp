#include <iostream>
#include <algorithm>

using namespace std;

typedef struct {
    int idx;
    int t, s;
} info;

info s[1001];

bool myComp(info a, info b) {
    int c1 = a.s * b.t;
    int c2 = b.s * a.t;
    if(c1 == c2) return (a.idx < b.idx);
    else return (c1 > c2);
}

void solve(int n) {
    sort(s+1, s+n+1, myComp);
    for(int i = 1; i <= n; i++) {
        cout << s[i].idx << ' ';
    }
    cout << '\n';
}

int main( ) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> s[i].t >> s[i].s;
        s[i].idx = i;
    }
    
    solve(n);
    
    return 0;
}
