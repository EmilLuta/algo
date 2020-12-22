#include <bits/stdc++.h>

using namespace std;

long long solution(int N, int S, int R) {
    if (N == 1 && S == 0) {
        return 1;
    }
    string r_pos = to_string(R);
    int r_n = r_pos.size();
    vector<vector<vector<long long>>> dp(N + 1, vector<vector<long long>>(S + 1, vector<long long>(2, 0)));
    dp[0][0][1] = 1;
    for (int p = 0; p < min(N, r_n); p++) {
        for (int s = 0; s <= S; s++) {
            int up_to_digit = p == 0 ? min(r_pos[0] - '0', S + 1) : 9;
            for (int digit = (p == 0 ? 1 : 0); digit <= up_to_digit && s + digit <= S; digit++) {
                dp[p+1][s+digit][0] += dp[p][s][0];
                if (digit == r_pos[p] - '0') {
                    dp[p+1][s+digit][1] += dp[p][s][1];
                }
                if (digit < r_pos[p] - '0') {
                    dp[p+1][s+digit][0] += dp[p][s][1];
                }
            }
        }
    }
    return dp[r_n][S][1] + dp[r_n][S][0];
}

int main() {
    int N, S, R;
    scanf("%d%d%d", &N, &S, &R);
    printf("%lld\n", solution(N, S, R));
}
