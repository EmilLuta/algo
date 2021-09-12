#include <bits/stdc++.h>

using namespace std;

void print_dp(vector<vector<int>>& dp) {
    int a = dp.size();
    int b = dp[0].size();
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, 1e9 + 7));
    for (int i = 1; i <= a; i++) {
        dp[i][1] = i - 1;
    }
    for (int i = 1; i <= b; i++) {
        dp[1][i] = i - 1;
    }
    /* print_dp(dp); */
    for (int r = 2; r <= a; r++) {
        for (int c = 2; c <= b; c++) {
            if (r == c) {
                dp[r][c] = 0;
                continue;
            }
            for (int i = 1; i < r; i++) {
                /* printf("deciding for dp[%d][%d] as dp[%d][%d] + dp[%d][%d]\n", r, c, i, c, r - i, c); */
                dp[r][c] = min(dp[r][c], dp[i][c] + dp[r - i][c] + 1);
            }
            for (int i = 1; i < c; i++) {
                /* printf("deciding for dp[%d][%d] as dp[%d][%d] + dp[%d][%d]\n", r, c, r, i, r, c - i); */
                dp[r][c] = min(dp[r][c], dp[r][i] + dp[r][c - i] + 1);
            }
        }
    }
    printf("%d\n", dp[a][b]);
    /* print_dp(dp); */
}
