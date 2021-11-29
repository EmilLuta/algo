#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    long long answer = 0;
    long long left = 0, right = 1e18 / k;
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        long long s = 0;
        for (int i = 0; i < n; i++) {
            s += min(a[i], mid);
        }
        if (mid * k <= s) {
            left = mid + 1;
            answer = mid;
        } else {
            right = mid - 1;
        }
    }
    printf("%lld\n", answer);
}
