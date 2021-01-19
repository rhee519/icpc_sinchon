#include <iostream>
#include <algorithm>

#define SIZE        100'000 + 1

using namespace std;

unsigned long long arr[SIZE];

unsigned long long getTotal(unsigned long long m, unsigned long long n, unsigned long long sum) {
    unsigned long long total = 0ull;
    unsigned long long rmd = sum - m;
    sort(arr, arr+n); // sort arr in ascending order
    
    for(int i = 0; i < n; i++) {
        unsigned long long r = min(arr[i], rmd/(n-i));
        arr[i] = r; rmd -= r;
        total += r * r;
    }
    
    return total;
}

int main( ) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    
    unsigned long long m, n;
    unsigned long long sum = 0ull;
    unsigned long long total;
    cin >> m >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    
    total = getTotal(m, n, sum);
    cout << total << '\n';
    
    return 0;
}
