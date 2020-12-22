#include <bits/stdc++.h>

using namespace std;

# define deb_v(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << a[i] << " "; \
    cerr << ")\n";

# define deb(x) cerr << #x << " = " << x << "\n";

void solve(int t) {
    int n, k;
    scanf("%d%d", &n, &k);
    int m = n * k;
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        scanf("%d", & a[i]);
    }
    int diff = (n + 2) / 2;
    long long answer = 0;
    for (int i = 1; i <= k; i++) {
        answer += a[m - i * diff];
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
