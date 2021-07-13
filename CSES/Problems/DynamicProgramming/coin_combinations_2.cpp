#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int dp[1000005][105];

int main() {
    int n, x;
    scanf("%d%d", &n, &x);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    /* vector<vector<int>> dp(x + 1, vector<int>(n, 0)); */
    dp[0][0] = 1;
    for (int s = 0; s <= x; s++) {
        for (int i = 0; i < n; i++) {
            int target = s + a[i];
            if (target <= x) {
                dp[target][i] += dp[s][i];
                if (dp[s][i + 1] >= MOD) {
                    dp[target][i] -= MOD;
                }
            }
            if (i + 1 < n) {
                dp[s][i + 1] += dp[s][i];
                if (dp[s][i + 1] >= MOD) {
                    dp[s][i + 1] -= MOD;
                }
            }
        }
    }
    printf("%d\n", dp[x][n - 1]);
}
