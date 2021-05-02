#include <bits/stdc++.h>

using namespace std;

// ios::sync_with_stdio(0);
// cin.tie(0);

# define deb_v(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << a[i] << " "; \
    cerr << ")\n";

# define deb(x) cerr << #x << " = " << x << "\n";

bool not_ok(int h, int low, int high, int k) {
    return h + k - 1 + k <= low || h >= high;
}

void solve(int t) {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int low = a[0];
    int high = a[0] + k;
    for (int i = 1; i < n - 1; i++) {
        if (not_ok(a[i], low, high, k)) {
            printf("NO\n");
            return;
        }
        low = max(a[i], low - (k - 1));
        high = min(high - 1, a[i] + k - 1) + k;
    }
    if (a[n - 1] + k <= low || a[n - 1] >= high) {
        printf("NO\n");
        return;
    }
    printf("YES\n");
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
