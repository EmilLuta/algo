#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int MAX_N = 1e6 + 5;

int main() {
    int n, x;
    scanf("%d%d", &n, &x);
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }
    vector<int> dp(MAX_N, 0);
    dp[0] = 1;
    for (int i = 0; i < x; i++) {
        if (dp[i] == 0) {
            continue;
        }
        for (int coin : coins) {
            int target = coin + i;
            if (target <= x) {
                dp[target] += dp[i];
                dp[target] %= MOD;
            }
        }
    }
    printf("%d\n", dp[x]);
}
