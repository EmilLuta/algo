#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    scanf("%d", &n);
    vector<bool> taken(n, false);
    int all = n * (n + 1) / 2;
    if (all % 2 != 0) {
        printf("0\n");
        return 0;
    }
    int target = all / 2;
    vector<long long> dp(target + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = target; j >= 0; j--) {
            if (j + i <= target) {
                dp[j + i] += dp[j];
                dp[j + i] %= 2 * MOD;
            }
        }
    }
    printf("%lld\n", ((dp[target]) / 2) % MOD);
}
