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
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    vector<int> ones(32);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a.begin(), a.end());
    if (a[0] != a[1]) {
        printf("0\n");
        return;
    }
    for (int i = 2; i < n; i++) {
        if ((a[0] & a[i])!= a[0]) {
            printf("0\n");
            return;
        }
    }
    int s_c = 0;
    for (int i = 0; i < n; i++) {
        if (a[0] == a[i]) {
            s_c++;
            continue;
        }
        break;
    }
    long long smallest_possible = 0;
    for (int i = 1; i < s_c; i++) {
        smallest_possible += i * 2;
        smallest_possible %= MOD;
    }
    long long middle = 1;
    for (int i = 2; i <= n - 2; i++) {
        middle *= i;
        middle %= MOD;
    }
    printf("%lld\n", (middle * smallest_possible) % MOD);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
