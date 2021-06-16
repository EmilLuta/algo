#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, k;
    scanf("%lld%lld", &n, &k);
    vector<pair<long long, long long>> a(n);
    for (long long i = 0; i < n; i++) {
        scanf("%lld%lld", &a[i].first, &a[i].second);
    }
    sort(a.begin(), a.end());
    for (long long i = 0; i < n; i++) {
        if (a[i].first <= k) {
            k += a[i].second;
            continue;
        }
        break;
    }
    printf("%lld\n", k);
}
