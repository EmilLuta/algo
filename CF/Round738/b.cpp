#include <bits/stdc++.h>

using namespace std;

// ios::sync_with_stdio(0);
// cin.tie(0);

# define deb_v(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << item << " "; \
    cerr << ")\n";

# define deb(x) cerr << #x << " = " << x << "\n";

# define deb_v_p(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << "(" << item.first << ", " << item.second << ") "; \
    cerr << ")\n";

void solve(int t) {
    int n;
    scanf("%d", &n);
    string s;
    cin >> s;
    vector<pair<int, int>> dp(n, {1e9, 1e9}); // {blue, red}
    if (s[0] == '?') {
        dp[0].first = 0;
        dp[0].second = 0;
    } else {
        if (s[0] == 'B') {
            dp[0].first = 0;
        } else {
            dp[0].second = 0;
        }
    }
    for (int i = 1; i < n; i++) {
        if (s[i] == '?') {
            dp[i].first = min(dp[i - 1].first + 1, dp[i - 1].second);
            dp[i].second = min(dp[i - 1].second + 1, dp[i - 1].first);
        } else if (s[i] == 'B') {
            dp[i].first = min(dp[i - 1].first + 1, dp[i - 1].second);
        } else {
            dp[i].second = min(dp[i - 1].second + 1, dp[i - 1].first);
        }
    }
    s[n - 1] = dp[n - 1].first > dp[n - 1].second ? 'R' : 'B';
    for (int i = n - 2; i >= 0; i--) {
        if (s[i + 1] == 'B') {
            if (dp[i].first + 1 == dp[i + 1].first) {
                s[i] = 'B';
            } else {
                s[i] = 'R';
            }
        } else {
            if (dp[i].second + 1 == dp[i + 1].second) {
                s[i] = 'R';
            } else {
                s[i] = 'B';
            }
        }
    }
    cout << s << endl;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
