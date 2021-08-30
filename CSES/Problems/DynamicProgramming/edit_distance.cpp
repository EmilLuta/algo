#include <bits/stdc++.h>

using namespace std;

void min_self(int& a, int b) {
    a = min(a, b);
}

int main() {
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1e7));
    for (int i = 0; i <= n; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= m; j++) {
        dp[0][j] = j;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char ac = a[i - 1], bc = b[j - 1];
            if (ac == bc) {
                min_self(dp[i][j], dp[i - 1][j - 1]);
            }
            min_self(dp[i][j], dp[i - 1][j] + 1); // erase b[j]
            min_self(dp[i][j], dp[i][j - 1] + 1); // add what we need before b[j]
            min_self(dp[i][j], dp[i - 1][j - 1] + 1); // change b[j] to a[i]
        }
    }
    printf("%d\n", dp[n][m]);
}
