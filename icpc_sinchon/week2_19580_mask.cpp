#include <iostream>
#include <map>

using namespace std;
#define SIZE        10 + 1

bool myComp(pair<long long, long long> p1, pair<long long, long long> p2) {
    if(p1.second == p2.second) return p2.first < p1.first;
    return p1.second < p2.second;
}

map<long long, int> m;    // <price of mask, # of masks left>
pair<long long, long long> r[SIZE];     // <lower_bound, upper_bound>

int main( ) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> r[i].first >> r[i].second;
    }
    
    
    return 0;
}
