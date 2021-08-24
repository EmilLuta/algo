#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<vector<int>> dp(n, vector<int>(3, 0));
    for (int i = 0; i < n; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if (i == 0) {
            dp[i][0] = a;
            dp[i][1] = b;
            dp[i][2] = c;
            continue;
        }
        dp[i][0] = a + max(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = b + max(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = c + max(dp[i - 1][0], dp[i - 1][1]);
    }
    printf("%d\n", max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2])));
}
