#include <iostream>
#include <algorithm>

#define SIZE        200'000 + 1
using namespace std;

struct info{
    int a, b; // 0 <= a, b <= 40,000
    bool operator <(const info &other) const {
        // b/a < other.b/other.a
        if(a == 0) return false;
        else if(other.a == 0) return true;
        else if(b == 0 && other.b == 0) return a < other.a;
        else return b * other.a < other.b * a;
    }
};

info arr[SIZE];

int getTotalTime(int n) {
    int total_time = 0;
    
    sort(arr, arr+n);
    // sort in descending order by a/b
    
    for(int i = 0; i < n; i++) {
        total_time += arr[i].a * total_time + arr[i].b;
        total_time %= 40'000;
    }
    
    return total_time;
}

int main( ) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    int n;
    int total_time;
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i].a >> arr[i].b;
    }
    
    total_time = getTotalTime(n);
    cout << total_time << '\n';
    
    return 0;
}
