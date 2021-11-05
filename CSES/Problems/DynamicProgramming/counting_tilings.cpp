#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

bool can_fill(int m1, int m2, const int MASK) {
    if ((m1 & m2) != 0) {
        return false;
    }
    int x = (!(m1 | m2)) & MASK;
    if (x % 3 != 0) {
        return false;
    }
    x /= 3;
    if ((x & (x << 2)) != 0) {
        return false;
    }
    return true;
}

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
    const int MASK = 1 << n;
    vector<vector<int>> dp(m + 1, vector<int>(MASK, 0));
    dp[0][0] = 1;
    for (int i = 0; i < m; i++) {
        for (int m1 = 0; m1 < MASK; m1++) {
            for (int m2 = 0; m2 < MASK; m2++) {
                if (can_fill(m1, m2, MASK)) {
                    dp[i + 1][m2] += dp[i][m1];
                    dp[i + 1][m2] %= MOD;
                }
            }
        }
    }
    for (int i = 0; i <= m; i++) {
        for (int mask = 0; mask < MASK; mask++) {
            cout << "dp[" << i << "][" << bin(mask) << "] = " << dp[i][mask] << "\n";
        }
        printf("\n");
    }
    printf("%d\n", dp[m][0]);
}
