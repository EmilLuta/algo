#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    vector<int> dp(n, 1e9 + 7);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < min(i + k + 1, n); j++) {
            dp[j] = min(dp[j], dp[i] + abs(a[i] - a[j]));
        }
    }
    printf("%d\n", dp[n - 1]);
}
