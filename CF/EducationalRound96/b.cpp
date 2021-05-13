#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a.begin(), a.end());
    if (k == 0) {
        printf("%lld\n", a[n - 1] - a[0]);
        return;
    }
    int index = n - 2;
    while (k > 0 && index >= 0) {
        a[n - 1] += a[index];
        index--;
        k--;
    }
    printf("%lld\n", a[n - 1]);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
