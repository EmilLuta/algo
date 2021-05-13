#include <bits/stdc++.h>

using namespace std;

// ios::sync_with_stdio(0);
// cin.tie(0);

# define deb_v(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << a[i] << " "; \
    cerr << ")\n";

# define deb(x) cerr << #x << " = " << x << "\n";

void solve(int t) {
    int w, h, n;
    scanf("%d%d%d", &w, &h, &n);
    int c_w = 0, c_h = 0;
    while ((w & 1) == 0) {
        c_w++;
        w >>= 1;
    }
    while ((h & 1) == 0) {
        c_h++;
        h >>= 1;
    }
    if (1 << (c_h + c_w) >= n) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
