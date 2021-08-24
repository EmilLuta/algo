#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    vector<int> dp(n, 1e9 + 7);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        if (i + 1 < n) {
            dp[i + 1] = min(dp[i + 1], dp[i] + abs(a[i] - a[i + 1]));
        }
        if (i + 2 < n) {
            dp[i + 2] = min(dp[i + 2], dp[i] + abs(a[i] - a[i + 2]));
        }
    }
    printf("%d\n", dp[n - 1]);
}
