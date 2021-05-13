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
int const JUMP = 1e5 * 2 + 1;


void solve(int t, vector<vector<vector<int>>>& cache) {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<long long> digits_at(10, 0);
    vector<long long> new_digits_at(10, 0);
    while (n != 0) {
        digits_at[n % 10]++;
        n /= 10;
    }
    for (int d = 0; d <= 9; d++) {
        if (digits_at[d] > 0) {
            for (int n_d = 0; n_d <= 9; n_d++) {
                new_digits_at[n_d] += ((digits_at[d] * cache[d][m][n_d]) % MOD);
                new_digits_at[n_d] %= MOD;
            }
        }
    }
    digits_at = new_digits_at;
    long long answer = 0;
    for (int i = 0; i <= 9; i++) {
        answer += digits_at[i];
        answer %= MOD;
    }
    printf("%lld\n", answer);
}

int main() {
    vector<vector<vector<int>>> x(10, vector<vector<int>>(JUMP + 1, vector<int>(10, 0)));
    for (int s_d = 0; s_d <= 9; s_d++) {
        vector<int> digits_at(10, 0);
        vector<int> new_digits_at(10, 0);
        digits_at[s_d]++;
        x[s_d][0][s_d]++;
        for (int i = 1; i <= JUMP; i++) {
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
                x[s_d][i][d] = digits_at[d];
            }
        }
    }
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i, x);
    }
}
