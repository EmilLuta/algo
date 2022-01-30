#include <bits/stdc++.h>

using namespace std;

const long long MAX = 1e9 * 2 + 5;

void solve(int t) {
    int n;
    long long k;
    scanf("%d%lld", &n, &k);
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a.begin(), a.end());
    vector<long long> pref(n, 0);
    pref[0] = a[0];
    for (int i = 1; i < n; i++) {
        pref[i] = pref[i - 1] + a[i];
    }
    long long answer = MAX;
    for (int i = 0; i < n; i++) {
        long long sum_to_cover = k - (pref[i] - a[0]);
        int sign = 1;
        if (sum_to_cover < 0) {
            sign = -1;
        }
        long long target = abs(sum_to_cover) / (n - i);
        target *= sign;
        answer = min(answer, max(0ll, max(0ll, a[0] - target) + n - i - 1));
    }
    printf("%lld\n", answer);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
