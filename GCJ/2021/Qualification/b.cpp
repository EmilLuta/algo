#include <bits/stdc++.h>

using namespace std;

void min_self(int& a, int b) {
    a = min(a, b);
}

void solve(int t) {
    int x, y;
    string s;
    cin >> x >> y >> s;
    int n = s.size();
    vector<pair<int, int>> dp(n + 1, {1000000, 1000000}); // first = 'C', second = 'J';
    dp[0] = {0, 0};
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') {
            min_self(dp[i + 1].first, dp[i].first);
            min_self(dp[i + 1].first, dp[i].second + y);
            min_self(dp[i + 1].second, dp[i].second);
            min_self(dp[i + 1].second, dp[i].first + x);
        } else if (s[i] == 'C') {
            min_self(dp[i + 1].first, dp[i].first);
            min_self(dp[i + 1].first, dp[i].second + y);
        } else if (s[i] == 'J') {
            min_self(dp[i + 1].second, dp[i].second);
            min_self(dp[i + 1].second, dp[i].first + x);
        } else {
            assert(false);
        }
        /* printf("dp[%d] = {%d, %d}\n", i + 1, dp[i + 1].first, dp[i + 1].second); */
    }
    printf("Case #%d: %d\n", t, min(dp[n].first, dp[n].second));
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        solve(t);
    }
}
