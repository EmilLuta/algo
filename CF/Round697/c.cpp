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
    int n_a, n_b, n;
    scanf("%d%d%d", &n_a, &n_b, &n);
    vector<int> a(n), b(n);
    vector<int> boys(n_a + 1, 0), girls(n_b + 1, 0);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        boys[a[i]]++;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        girls[b[i]]++;
    }
    long long answer = 0;
    for (int i = 0; i < n; i++) {
        answer += n - (boys[a[i]] + girls[b[i]] - 1);
    }
    printf("%lld\n", answer / 2);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
