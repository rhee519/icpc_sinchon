#include <iostream>
#include <algorithm>

using namespace std;
#define SIZE    10 + 1

int arr[SIZE];
int sorted[SIZE];

int dnc(int left, int right) {
    if(left >= right) return 0;
    
    int mid = (left+right)/2;
    int ret;
    
    return 0;
}

int main( ) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    
    return 0;
}
