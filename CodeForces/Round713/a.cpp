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
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < n - 1; i++) {
        if (a[i] == a[i - 1] && a[i] != a[i + 1]) {
            printf("%d\n", i + 2);
            return;
        }
        if (a[i] == a[i + 1] && a[i] != a[i - 1]) {
            printf("%d\n", i);
            return;
        }
        if (a[i + 1] == a[i - 1] && a[i] != a[i - 1]) {
            printf("%d\n", i + 1);
            return;
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
