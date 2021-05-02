#include <bits/stdc++.h>

using namespace std;

// ios::sync_with_stdio(0);
// cin.tie(0);

# define deb_v(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << a[i] << " "; \
    cerr << ")\n";

# define deb(x) cerr << #x << " = " << x << "\n";

void solve(int t) {
    int n, m;
    cin >> n;
    vector<int> r(n);
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    int best_r = 0;
    int curr_r = 0;
    for (int i = 0; i < n; i++) {
        curr_r += r[i];
        best_r = max(best_r, curr_r);
    }
    int best_b = 0;
    int curr_b = 0;
    for (int i = 0; i < m; i++) {
        curr_b += b[i];
        best_b = max(best_b, curr_b);
    }
    printf("%d\n", max(best_b, max(best_r, best_r + best_b)));
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
