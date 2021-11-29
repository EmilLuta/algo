#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

string bin(int n) {
    string s(4, '0');
    int index = 3;
    while (n != 0) {
        if (n % 2 == 1) {
            s[index] = '1';
        }
        index--;
        n /= 2;
    }
    return s;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<vector<int>> dp(m + 1, vector<int>(1 << n, 0)); // the number of ways to arrive at this form (mask) on column j
    dp[0][0] = 1;
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            for (int mask = 0; mask < (1 << n); mask++) {
                dp[j + 1][mask] = dp[j][mask ^ (1 << i)];
                if (i && !(mask & (1 << i)) && !(mask & (1 << (i - 1)))) {
                    dp[j + 1][mask] += dp[j][mask ^ (1 << (i - 1))];
                }
                if (dp[j + 1][mask] >= MOD) {
                    dp[j + 1][mask] -= MOD;
                }
            }
            for (int mask = 0; mask < (1 << n); mask++) {
                dp[j][mask] = dp[j + 1][mask];
            }
        }
    }
    for (int i = 0; i <= m; i++) {
        for (int mask = 0; mask < 1 << n; mask++) {
            cout << "dp[" << i << "][" << bin(mask) << "] = " << dp[i][mask] << "\n";

        }
        printf("\n");
    }
    cout << dp[m][0] << endl;
}
