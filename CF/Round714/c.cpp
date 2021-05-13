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

int const MOD = 1e9 + 7;

void solve(int t) {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<long long> digits_at(10, 0);
    vector<long long> new_digits_at(10, 0);
    while (n != 0) {
        digits_at[n % 10]++;
        n /= 10;
    }
    for (int i = 0; i < m; i++) {
        for (int d = 0; d <= 8; d++) {
            new_digits_at[d + 1] += digits_at[d];
            new_digits_at[d + 1] %= MOD;
        }
        new_digits_at[0] += digits_at[9];
        new_digits_at[0] %= MOD;
        new_digits_at[1] += digits_at[9];
        new_digits_at[1] %= MOD;
        digits_at = new_digits_at;
        for (int d = 0; d <= 9; d++) {
            new_digits_at[d] = 0;
        }
        long long sum = 0;
        for (int d = 0; d <= 9; d++) {
            sum += digits_at[d];
        }
        printf("after step %d we got %lld\n", i + 1, sum);
    }
    long long answer = 0;
    for (int d = 0; d < 10; d++) {
        answer += digits_at[d];
        answer %= MOD;
    }
    printf("%lld\n", answer);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
