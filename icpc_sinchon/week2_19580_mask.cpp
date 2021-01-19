#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
#define SIZE        10 + 1

bool myComp(pair<long long, long long> p1, pair<long long, long long> p2) {
    // compare function for citizen info
    // <lower_bound, upper_bound>
    if(p1.second == p2.second) return p2.first < p1.first;
    return p1.second < p2.second;
}

map<long long, int> mask;    // <price of mask, # of masks left>
pair<long long, long long> r[SIZE];     // <lower_bound, upper_bound>

int count(int n) {
    int cnt = 0;
    
    sort(r, r+n, myComp);   // sort citizen information in myComp-order
    // map is sorted in key-ascending-order
    for(int i = 0; i < n; i++) {
        
    }
    
    
    return cnt;
}

int main( ) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    
    int n, m;
    int cnt;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> r[i].first >> r[i].second;
    }
    for(int i = 0; i < m; i++) {
        pair<long long, int> tmp;
        cin >> tmp.first >> tmp.second;
        map<long long, int>::iterator it = mask.find(tmp.first);
        if(it == mask.end()) { // new key
            mask[tmp.first] = tmp.second;
        }
        else { // already exists
            mask[tmp.first] += tmp.second;
        }
    }
    
    cnt = count(n);
    cout << cnt << '\n';
    
    return 0;
}
