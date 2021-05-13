#include <bits/stdc++.h>

using namespace std;

int dp[205][205][205];
const int N = 3;

void max_self(int& a, int b) {
    a = max(a, b);
}

// dp[i][j][k] - prefixes are done, now looking at a[i], b[j], c[k]
// start at dp[0][0][0]

int main() {
    vector<int> sizes(N);
    scanf("%d%d%d", &sizes[0], &sizes[1], &sizes[2]);
    vector<vector<int>> v(N);
    for (int i = 0; i < N; i++) {
        v[i].resize(sizes[i]);
        for (int j = 0; j < sizes[i]; j++) {
            scanf("%d", &v[i][j]);
        }
        sort(v[i].rbegin(), v[i].rend()); // sorts decreasingly
        v[i].push_back(0); // sentinel
    }
    int answer = 0;
    for (int i = 0; i <= sizes[0]; i++) {
        for (int j = 0; j <= sizes[1]; j++) {
            for (int k = 0; k <= sizes[2]; k++) {
                max_self(answer, dp[i][j][k]);
                max_self(dp[i + 1][j + 1][k], dp[i][j][k] + v[0][i] * v[1][j]);
                max_self(dp[i + 1][j][k + 1], dp[i][j][k] + v[0][i] * v[2][k]);
                max_self(dp[i][j + 1][k + 1], dp[i][j][k] + v[1][j] * v[2][k]);
            }
        }
    }
    printf("%d\n", answer);
}
