#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, k; cin >> n >> k;
    vector<long long> v(n);
    for(long long &x : v) cin >> x;
    long long ok = 0, ng = 1e18 / k;
    while(ng - ok > 1){
        long long md = (ok + ng) / 2, sum = 0;
        for(long long x : v) sum += min(x, md);
        if(sum >= k * md) ok = md;
        else ng = md;
    }
    cout << ok << endl;
}
