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
    long long n, m, x;
    scanf("%lld%lld%lld", &n, &m, &x);
    long long c = x / n + (x % n != 0);
    long long r = (x - x / n * n) - 1;
    if (r < 0) {
        r += n;
    }
    /* printf("r = %lld, c = %lld\n", r, c); */
    printf("%lld\n", r * m + c);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
