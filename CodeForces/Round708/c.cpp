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
    for (int i = 3; i < k; i++) {
        printf("1 ");
    }
    n -= k;
    n += 3;
    if (n % 2 == 1) {
        printf("%d %d %d\n", n / 2, n / 2, 1);
        return;
    }
    if (n % 4 == 0) {
        printf("%d %d %d\n", n / 2, n / 4, n / 4);
        return;
    }
    printf("%d %d %d\n", n / 2 - 1, n / 2 - 1, 2);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(t);
    }
}
