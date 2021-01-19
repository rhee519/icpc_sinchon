#include <iostream>
#include <algorithm>

using namespace std;
#define SIZE        100'000 + 1

// bool docked[SIZE];
int gate[SIZE];

void init(int g) {
    for(int i = 1; i <= g; i++) {
        gate[i] = i;
    }
}

int find(int x) {
    if(x == gate[x]) return x;
    
    return (gate[x] = find(gate[x]));
}

int main( ) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    
    int g, p;
    int cnt = 0;
    cin >> g >> p;
    init(g);
    for(int i = 1; i <= p; i++) {
        int plane; cin >> plane; // Gi
        plane = min(plane, g);
        if(find(plane) == 0) break;
        gate[find(gate[plane])]--; cnt++;
    }
    
    cout << cnt << '\n';
    
    return 0;
}
