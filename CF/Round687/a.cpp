#include <bits/stdc++.h>

using namespace std;

// ios::sync_with_stdio(0);
// cin.tie(0);

# define deb_v(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << a[i] << " "; \
    cerr << ")\n";

# define deb(x) cerr << #x << " = " << x << "\n";

void solve(int t) {
    int n, m, r, c;
    scanf("%d%d%d%d", &n, &m, &r, &c);
    r--;
    c--;
    long long answer = r + c;
    answer = max(answer, (long long)(n - r - 1 + c));
    answer = max(answer, (long long)(n - r - 1 + m - c - 1));
    answer = max(answer, (long long)(r + m - c - 1));
    printf("%lld\n", answer);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
