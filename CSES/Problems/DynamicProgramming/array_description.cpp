#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

void update_for(vector<vector<int>>& dp, int i, int x, int m) {
    for (int t : {x - 1, x, x + 1}) {
        if (0 < t && t <= m && dp[i - 1][t] != 0) {
            dp[i][x] += dp[i - 1][t];
            if (dp[i][x] >= MOD) {
                dp[i][x] -= MOD;
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    // dp[i][x] = the number of ways to get to value x, at position i
    vector<vector<int>> dp(n, vector<int>(m + 1, 0));
    if (a[0] == 0) {
        for (int x = 1; x <= m; x++) {
            dp[0][x] = 1;
        }
    } else {
        dp[0][a[0]] = 1;
    }
    for (int i = 1; i < n; i++) {
        if (a[i] == 0) {
            for (int x = 1; x <= m; x++) {
                update_for(dp, i, x, m);
            }
        } else {
            update_for(dp, i, a[i], m);
        }
    }
    int answer = 0;
    for (int x = 1; x <= m; x++) {
        answer += dp[n - 1][x];
        if (answer >= MOD) {
            answer -= MOD;
        }
    }
    printf("%d\n", answer);
}
