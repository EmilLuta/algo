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

int gcd(int a, int b) {
    while (b != 0) {
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

int const MAX_A = 1e6 + 5;
bool is_prime[MAX_A];
int can_form[MAX_A];

void solve(int t) {
    int n;
    scanf("%d", &n);
    map<int, int> c;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        c[can_form[x]]++;
    }
    int zero = 0;
    int ones = 0;
    int more = 0;
    for (pair<int, int> p : c) {
        zero = max(zero, p.second);
        if (p.first == 1 || p.second % 2 == 0) {
            ones += p.second;
        } else {
            more = max(more, p.second);
        }
    }
    more = max(more, ones);
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        long long w;
        scanf("%lld", &w);
        if (w == 0) {
            printf("%d\n", zero);
        } else {
            printf("%d\n", more);
        }
    }
}

int main() {
    for (int i = 2; i < MAX_A; i++) {
        is_prime[i] = true;
    }
    for (int i = 1; i < MAX_A; i++) {
        can_form[i] = 1;
    }
    for (int i = 2; i < MAX_A; i++) {
        if (is_prime[i]) {
            can_form[i] = i;
            for (int j = i + i; j < MAX_A; j += i) {
                is_prime[j] = false;
                if (can_form[j / i] % i != 0) {
                    can_form[j] *= i;
                }
            }
        }
    }
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
