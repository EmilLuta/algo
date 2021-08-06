#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int d = 1; d <= 6; d++) {
            if (i - d >= 0) {
                dp[i] += dp[i - d];
                dp[i] %= MOD;
            }
        }
    }
    printf("%d\n", dp[n]);
}

