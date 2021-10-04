#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(4, 0)));
    // ( -- 0
    // ) -- 1
    // u -- 2
    // m -- 3
    dp[0][0][0] = 1;
    dp[0][0][3] = 1;
    for (int c = 1; c < m; c++) {
        dp[0][c][0] += dp[0][c - 1][1] + dp[0][c - 1][3];
        dp[0][c][1] += dp[0][c - 1][0];
        dp[0][c][3] += dp[0][c - 1][1] + dp[0][c - 1][3];
    }
    /* for (int r = 1; r < n; r++) { */
    /*     for (int c = 0; c < m; c++) { */
    /*         dp[r][c][0] += dp[ */
    /*     } */
    /* } */

    printf("For m we got: [");
    for (int c = 0; c < m; c++) {
        printf("%d ", dp[0][c][3]);
    }
    printf("]\n");

    printf("For ( we got: [");
    for (int c = 0; c < m; c++) {
        printf("%d ", dp[0][c][0]);
    }
    printf("]\n");

    printf("For u we got: [");
    for (int c = 0; c < m; c++) {
        printf("%d ", dp[0][c][2]);
    }
    printf("]\n");

    printf("For ) we got: [");
    for (int c = 0; c < m; c++) {
        printf("%d ", dp[0][c][1]);
    }
    printf("]\n");
}
