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

const int MOD = 1e9 + 7;

void solve(int t) {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    /* vector<map<long long, long long>> dp(n); // dp[i][sum] = how_many; when we reach index i, we can come up with indicies where the sum up them, inclusive is sum. Since multiple can have the same sum, we need to know how many have it. */
    map<long long, long long> curr, previous;
    previous[a[0]] = 1;
    for (int i = 1; i < n; i++) {
        for (pair<long long, long long> sum_times : previous) {
            long long sum = sum_times.first;
            long long times = sum_times.second;
            long long dif = a[i] - sum;
            curr[sum + dif] += times;
            curr[sum + dif] %= MOD;
            if (dif != a[i]) {
                curr[sum + a[i]] += times;
            }
            curr[sum + dif] %= MOD;
        }
        previous = curr;
        curr.clear();
    }
    long long answer = 0;
    for (pair<long long, long long> p : previous) {
        answer += p.second % MOD;
    }
    answer %= MOD;
    printf("%lld\n", answer);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
