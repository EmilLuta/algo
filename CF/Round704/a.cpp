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
    long long p, a, b, c;
    scanf("%lld%lld%lld%lld", &p, &a, &b, &c);
    long long answer = LLONG_MAX;
    answer = min(answer, (a - p % a) % a);
    answer = min(answer, (b - p % b) % b);
    answer = min(answer, (c - p % c) % c);
    printf("%lld\n", answer);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
