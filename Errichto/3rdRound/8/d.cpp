#include <bits/stdc++.h>

using namespace std;

int main() {
    int L;
    scanf("%d", &L);
    vector<vector<int>> dp(L + 1, vector<int>(10, 0));
    dp[0][0] = 1;
    for (int p = 0; p < L; p++) {
        for (int digit = 0; digit <= 9; digit++) {
            for (int d = 0; d <= 9; d++) {
                if (d != digit) {
                    dp[p + 1][digit] += dp[p][d];
                }
            }
        }
    }
    int answer = 0;
    for (int digit = 0; digit <= 9; digit++) {
        answer += dp[L][digit];
    }
    printf("%d\n", answer);
}
