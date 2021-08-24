#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int n;
    scanf("%d", &n);
    vector<vector<long long>> dp(n + 1, vector<long long>(3, 0));
    dp[0][0] = 2;
    dp[0][1] = 1;
    dp[0][2] = 4;
    for (int i = 1; i < n; i++) {
        dp[i][0] += 2 * dp[i - 1][0]  + dp[i - 1][1] + dp[i - 1][2];
        dp[i][1] += dp[i - 1][0] + dp[i - 1][1];
        dp[i][2] += 3 * dp[i - 1][0] + 3 * dp[i - 1][2];
    }
    long long answer = dp[n - 1][0] + dp[n - 1][1] + dp[n - 1][2];
    printf("%lld\n", answer);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        solve();
        t--;
    }
}
