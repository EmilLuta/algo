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

const int MOD = 998244353;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a[i].first, &a[i].second);
    }
    // dp[i][sum] = vals
    for (int i = 0; i < n; i++) {
        for (int x = a[i].first; x <= a[i].second; x++) {
            if (i == 0) {
                dp[i][x] = x;
                continue;
            }
            if (i == 1) {
                dp[i][x
                continue;
            }
        }
    }
}
