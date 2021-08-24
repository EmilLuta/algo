#include <bits/stdc++.h>

using namespace std;

const int MAX_V = 1e5 + 7;

int main() {
    int n, w;
    scanf("%d%d", &n, &w);
    vector<int> val(n), weight(n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &weight[i], &val[i]);
    }
    vector<vector<int>> dp(n + 1, vector<int>(MAX_V, 1e9 + 7));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int v = 0; v < MAX_V; v++) {
            dp[i + 1][v] = min(dp[i + 1][v], dp[i][v]);
            int target = v + val[i];
            if (target < MAX_V && dp[i][v] + weight[i] <= w) {
                dp[i + 1][target] = min(dp[i + 1][target], dp[i][v] + weight[i]);
            }
        }
    }
    for (int i = MAX_V - 1; i >= 1; i--) {
        if (dp[n][i] != 1e9 + 7) {
            printf("%d\n", i);
            return 0;
        }
    }
    /* for (int i = 0; i < n; i++) { */
    /*     for (int s = 1; s <= 30; s++) { */
    /*         printf("dp[%d][%d] = %d\n", i + 1, s, dp[i + 1][s]); */
    /*     } */
    /*     printf("\n"); */
    /* } */
}
