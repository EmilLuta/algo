#include <bits/stdc++.h>

using namespace std;

void print_dp(vector<vector<int>>& dp) {
    int n = dp.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    int answer = 0;
    for (int left = 0; left < n; left++) {
        for (int right = 0; left + right < n; right++) {
            if ((left + right) % 2 == 0) {
                dp[left][right + 1] = max(dp[left][right + 1], dp[left][right] + a[n - right - 1]);
                answer = max(answer, dp[left][right + 1]);
                dp[left + 1][right] = max(dp[left + 1][right], dp[left][right] + a[left]);
                answer = max(answer, dp[left + 1][right]);
            } else {
                dp[left][right + 1] = max(dp[left][right + 1], dp[left][right]);
                dp[left + 1][right] = max(dp[left + 1][right], dp[left][right]);
            }
        }
    }
    printf("%d\n", answer);
    print_dp(dp);
}
