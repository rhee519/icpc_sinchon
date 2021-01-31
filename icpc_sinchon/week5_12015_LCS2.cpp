#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define SIZE        1'000'000 + 1

vector<int> v;
int arr[SIZE];

int count(int n) {
    int cnt = 1;
    v.push_back(arr[0]);
    
    for(int i = 1; i < n; i++) {
        if(v.back() < arr[i]) {
            v.push_back(arr[i]); cnt++;
            continue;
        }
        // v.back() >= arr[i]
        auto idx = lower_bound(v.begin(), v.end(), arr[i]);
        *idx = arr[i];
    }
    
    return cnt;
}
int main( ) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << count(n) << '\n';
    
    return 0;
}
