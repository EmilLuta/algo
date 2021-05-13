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
    int min1 = 200, min2 = 200, maximum = 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if (x < min1) {
            min2 = min1;
            min1 = x;
        } else {
            min2 = min(min2, x);
        }
        maximum = max(maximum, x);
    }
    if (maximum <= k) {
        printf("YES\n");
        return;
    }
    if (min1 + min2 <= k) {
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
