#include <bits/stdc++.h>

using namespace std;

long long solution(int N, int S, int R) {
    if (N == 1 && S == 0) {
        return 1;
    }
    vector<int> r_pos;
    while (R != 0) {
        r_pos.push_back(R % 10);
        R /= 10;
    }
    reverse(r_pos.begin(), r_pos.end());
    int r_n = r_pos.size();
    vector<vector<vector<long long>>> dp(N + 1, vector<vector<long long>>(S + 1, vector<long long>(2, 0)));
    for (int s = 0; s <= S; s++) {
        for (int digit = 1; digit < min(r_pos[0], S + 1); digit++) {
            dp[1][digit][0] = 1;
        }
        if (r_pos[0] <= S) {
            dp[1][r_pos[0]][1] = 1;
        }
    }
    /* printf("at position %d\ndp = [", 1); */
    /* for (int x = 0; x <= S; x++) { */
    /*     printf("(false = %d, true = %d), ", dp[1][x][0], dp[1][x][1]); */
    /* } */
    /* printf("\n"); */
    for (int p = 1; p < min(N, r_n); p++) {
        for (int s = 0; s <= S; s++) {
            for (int digit = 0; digit <= 9 && s + digit <= S; digit++) {
                dp[p+1][s+digit][0] += dp[p][s][0];
                if (digit == r_pos[p]) {
                    dp[p+1][s+digit][1] += dp[p][s][1];
                }
                if (digit < r_pos[p]) {
                    dp[p+1][s+digit][0] += dp[p][s][1];
                }
            }
        }
        /* printf("at position %d\ndp = [", p + 1); */
        /* for (int x = 0; x <= S; x++) { */
        /*     printf("(false = %d, true = %d), ", dp[p + 1][x][0], dp[p + 1][x][1]); */
        /* } */
        /* printf("\n"); */
    }
    /* printf("%lld, %lld\n", dp[r_n][S][0], dp[r_n][S][1]); */
    return dp[r_n][S][1] + dp[r_n][S][0];
}

int main() {
    int N = 3 /* is this necessary, since I have R? */, S = 3, R = 300;
    printf("%lld\n", solution(N, S, R));
    /* printf("%lld\n", solution(2, 3, 31)); */
}
