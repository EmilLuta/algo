#include <bits/stdc++.h>

using namespace std;

// ios::sync_with_stdio(0);
// cin.tie(0);

# define deb_v(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << a[i] << " "; \
    cerr << ")\n";

# define deb(x) cerr << #x << " = " << x << "\n";

long long const MOD = 1e9 + 7;

void solve(int t) {
    int n;
    scanf("%d", &n);
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    set<long long> a_i_and_j;
    set<long long> a_j_or_k;
    int c = 0;
    long long answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a_i_and_j.insert((a[i] & a[j]) % MOD);
            for (int k = 0; k < n; k++) {
                a_j_or_k.insert((a[j] | a[k]) % MOD);
                c++;
                answer += (((a[i] & a[j]) % MOD) * ((a[j] | a[k]) % MOD) % MOD);
                answer %= MOD;
            }
        }
    }
    printf("c = %d, a[i] and a[j] size = %d, a[j] or a[k] size = %d\n", c, (int)a_i_and_j.size(), (int)a_j_or_k.size());
    printf("%lld\n", answer);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
