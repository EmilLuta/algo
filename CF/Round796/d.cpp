#include <bits/stdc++.h>

using namespace std;

long long growth(long long mins) {
    return mins * (mins - 1) / 2;
}

void solve() {
    long long n, k;
    scanf("%lld%lld", &n, &k);
    vector<long long> a(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        sum += a[i];
    }
    if (k >= n) {
        long long answer = growth(n) + sum;
        k -= n;
        answer += (k / n) * (k * (k - 1));
        int left = k % n;
        printf("%lld\n", growth(n) + sum);
        return;
    }
    long long curr_sum = 0;
    for (int i = 0; i < k; i++) {
        curr_sum += a[i];
    }
    long long max_sum = curr_sum;
    for (int i = k; i < n; i++) {
        curr_sum -= a[i - k];
        curr_sum += a[i];
        max_sum = max(max_sum, curr_sum);
    }
    printf("%lld\n", growth(k) + max_sum);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
