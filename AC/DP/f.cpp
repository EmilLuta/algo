#include <bits/stdc++.h>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i] == b[j]) {
                printf("ce plm\n");
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
            }
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            dp[i][j + 1] = max(dp[i][j + 1], dp[i][j]);
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
        }
    }
    printf("%d\n", dp[n][m]);
}
