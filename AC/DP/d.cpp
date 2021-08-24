#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, w;
    scanf("%d%d", &n, &w);
    vector<int> val(n), weight(n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &weight[i], &val[i]);
    }
    vector<vector<long long>> dp(n + 1, vector<long long>(w + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int s = 0; s <= w; s++) {
            dp[i][s] = max(dp[i][s], dp[i - 1][s]);
            int target = s + weight[i - 1];
            if (target <= w) {
                dp[i][target] = max(dp[i][target], dp[i - 1][s] + val[i - 1]);
            }
        }
    }
    long long answer = 0;
    for (int s = 0; s <= w; s++) {
        answer = max(answer, dp[n][s]);
    }
    printf("%lld\n", answer);
}
