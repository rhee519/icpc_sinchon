#include <iostream>
#include <algorithm>

#define SIZE        100'000 + 1
using namespace std;

typedef struct {
    int start, end;
} info;

info m[SIZE];

bool myComp(info a, info b) {
    if(a.end == b.end) return a.start < b.start;
    else return a.end < b.end;
}

int count(int n) {
    int cnt = 0;
    int current_time = 0;
    
    // sort by start_time & end_time
    sort(m, m + n, myComp);
    
    for(int i = 0; i < n; i++) {
        if(m[i].start < current_time) continue;
        current_time = m[i].end;
        cnt++;
    }
    
    return cnt;
}

int main( ) {
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int cnt;
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> m[i].start >> m[i].end;
    }
    
    cnt = count(n);
    cout << cnt << '\n';
    
    return 0;
}
