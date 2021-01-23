#include <iostream>

using namespace std;
// 2147483647

unsigned long long getRemainder(int a, int b, int c) {
    // if(b == 0) return 1ull;
    if(b == 1) return a % c;
    unsigned long long ret = getRemainder(a, b/2, c);
    ret *= ret; ret %= c;
    if(b%2 == 1) { // a^(b/2) * a^(b/2) =  a^(b-1)
        ret *= (a % c);
    }
    
    return ret % c;
}

int main( ) {
    int a, b, c;
    unsigned long long ans;
    cin >> a >> b >> c;
    
    ans = getRemainder(a, b, c);
    cout << ans << '\n';
    
    return 0;
}
