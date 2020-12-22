#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    long long s = 0;
    for (int i = 0; i < n; i += 2) {
        s += a[i];
    }
    long long k1 = 0, k2 = 0, best_k1 = 0, best_k2 = 0;
    for (int i = 0; i < n - 1; i += 2) {
        k1 = max((long long)0, k1 + (a[i + 1] - a[i]));
        best_k1 = max(best_k1, k1);
    }
    for (int i = 1; i < n - 1; i += 2) {
        k2 = max((long long)0, k2 + (a[i] - a[i + 1]));
        best_k2 = max(best_k2, k2);
    }
    printf("%lld\n", s + max(best_k1, best_k2));
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
