#include <bits/stdc++.h>

using namespace std;

void print_dp(vector<vector<long long>>& dp) {
    int n = dp.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lld ", dp[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    long long s = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        s += a[i];
    }
    vector<vector<long long>> dp(n, vector<long long>(n, 0));
    for (int left = n - 1; left >= 0; left--) {
        for (int right = left; right < n; right++) {
            if (left == right) {
                dp[left][right] = a[left];
                continue;
            }
            dp[left][right] = max(a[left] - dp[left + 1][right], a[right] - dp[left][right - 1]);
        }
    }
    printf("%lld\n", (s + dp[0][n - 1]) / 2);
}
