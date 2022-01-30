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
    int n, k;
    scanf("%d%d", &n, &k);
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].first);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].second);
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        if (a[i].first > k) {
            break;
        }
        k += a[i].second;
    }
    printf("%d\n", k);
}
int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
