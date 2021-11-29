#include <bits/stdc++.h>

using namespace std;

int const MOD = 1e9 + 7;

void apply_mod(int& x) {
    if (x >= MOD) {
        x -= MOD;
    }
}

// n rows
// m columns
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int MAX_MASK = 1 << n;
    vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(MAX_MASK, 0)));
    dp[0][0][0] = 1;
    for (int c = 0; c < m; c++) {
        for (int r = 0; r < n; r++) {
            int bit_r = 1 << r;
            int bit_r_1 = 1 << (r + 1);
            for (int mask = 0; mask < 1 << n; mask++) {
                if ((mask & bit_r) != 0) {
                    dp[c][r + 1][mask - bit_r] += dp[c][r][mask];
                    apply_mod(dp[c][r + 1][mask - bit_r]);
                } else {
                    dp[c][r + 1][mask + bit_r] += dp[c][r][mask];
                    apply_mod(dp[c][r + 1][mask + bit_r]);
                    if (r < n - 1 && (mask & bit_r_1) == 0) {
                        dp[c][r + 1][mask + bit_r_1] += dp[c][r][mask];
                        apply_mod(dp[c][r + 1][mask + bit_r_1]);
                    }
                }
            }
        }
        for (int mask = 0; mask < MAX_MASK; mask++) {
            dp[c + 1][0][mask] = dp[c][n][mask];
        }
    }
    printf("%d\n", dp[m][0][0]);
}
