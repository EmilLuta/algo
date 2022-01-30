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
    int l, r, k;
    scanf("%d%d%d", &l, &r, &k);
    if (l == 1 && r == 1) {
        printf("NO\n");
        return;
    }
    if (l == r) {
        printf("YES\n");
        return;
    }
    int ops = (r - l + 1) / 2;
    if (l % 2 != 0 && r % 2 != 0) {
        ops++;
    }
    if (ops <= k) {
        printf("YES\n");
        return;
    }
    printf("NO\n");
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
