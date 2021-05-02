#include <bits/stdc++.h>

using namespace std;

int C(int n, int k) {
    if (k > n || k < 0) {
        return 0;
    }
    int answer = 1;
    k = min(k, n - k);
    for (int i = 0; i < k; i++) {
        answer *= (n - i);
        answer /= (i + 1);
    }
    return answer;
}

void solve_binary_coeff(string s, int n, int k) {
    int answer = 0, ones = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            ones++;
            continue;
        }
        int left_ones = k - (ones + 1);
        int left = n - i - 1;
        answer += C(left, left_ones);
    }
    cout << answer << endl;
}

void solve_dp(string s, int n, int k) {
    if (n < k) {
        printf("0\n");
        return;
    }
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(2)));
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int ones = 0; ones <= i; ones++) {
            if (s[i] == '1') {
                dp[i + 1][ones + 1][0] += dp[i][ones][0];
            }
            if (s[i] == '0') {
                dp[i + 1][ones][0] += dp[i][ones][0];
                dp[i + 1][ones + 1][1] += dp[i][ones][0];
            }
            dp[i + 1][ones][1] += dp[i][ones][1];
            dp[i + 1][ones + 1][1] += dp[i][ones][1];
        }
    }
    printf("%d\n", dp[n][k][1]);
}

int main() {
    string s;
    int n, k;
    cin >> s >> k;
    n = s.size();
    solve_binary_coeff(s, n, k);
    solve_dp(s, n, k);
}

/* 5 ones */
/* 1 1 1 _ _ _ _ _ */
/*       _ _ */
/*       _   _ */
/*       _     _ */
/*       _       _ */
/*         _ _ */
/*         _   _ */
/*         _     _ */
/*           _ _ */
/*           _   _ */
/*             _ _ */
/* C(n, k) = n! / r!(n - r)! */
/* C(5, 2) = 5! / 2! * 3! */
/* 3 * 4 * 5 / 3! = 4 * 5 / 2 = 10 */
