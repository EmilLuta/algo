#include <bits/stdc++.h>

using namespace std;

# define deb_v(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << a[i] << " "; \
    cerr << ")\n";

# define deb(x) cerr << #x << " = " << x << "\n";


void solve(int t) {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            int x;
            scanf("%d", &x);
            if ((r + c) % 2 == 0) {
                if (x % 2 == 1) {
                    x++;
                }
            } else {
                if (x % 2 == 0) {
                    x++;
                }
            }
            printf("%d ", x);
        }
        printf("\n");
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
