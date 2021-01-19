#include <iostream>
#include <algorithm>
#include <queue>

#define SIZE        10 + 1
using namespace std;

struct employ{
    int s, q;
    bool operator<(const employ &other) const {
        // k = s/q
        if(s * other.q == other.s * q) return q < other.q;
        else return s * other.q < other.s * q;
    }
};

bool comp_pq(employ a, employ b) {
    return a.q < b.q;
}

employ arr[SIZE];

int getMaxNum(int n, long long w) {
    int max_num = 0;
    long long sum_of_q = 0;
    double kmin = 0.0;
    vector<employ> v;
    
    
    
    
    return max_num;
}

int main( ) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    int n;
    long long w;
    cin >> n >> w;
    for(int i = 0; i < n; i++) {
        cin >> arr[i].s >> arr[i].q;
    }
    
    getMaxNum(n, w);
    
    return 0;
}
