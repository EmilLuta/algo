#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int dp[105][1000005];

int main() {
    int n, x;
    scanf("%d%d", &n, &x);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int s = 0; s <= x; s++) {
            int target = s + a[i];
            if (target <= x) {
                dp[i][target] += dp[i][s];
                if (dp[i][target] >= MOD) {
                    dp[i][target] -= MOD;
                }
            }
            if (i + 1 < n) {
                dp[i + 1][s] += dp[i][s];
                if (dp[i + 1][s] >= MOD) {
                    dp[i + 1][s] -= MOD;
                }
            }
        }
    }
    printf("%d\n", dp[n - 1][x]);
}
