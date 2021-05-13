#include <bits/stdc++.h>

using namespace std;

// ios::sync_with_stdio(0);
// cin.tie(0);

# define deb_v(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << a[i] << " "; \
    cerr << ")\n";

# define deb(x) cerr << #x << " = " << x << "\n";

void solve(int t) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int s = a + b + c;
    int diff = s / 7;
    if ((a < diff) || (b < diff) || (c < diff) || ((s - 2 * diff) % 7 != 0)) {
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
