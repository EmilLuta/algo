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
    if (a[n - 1] == 0) {
        for (int i = 1; i <= n + 1; i++) {
            printf("%d ", i);
        }
        printf("\n");
        return;
    }
    if (a[0] == 1) {
        printf("%d ", n + 1);
        for (int i = 1; i <= n; i++) {
            printf("%d ", i);
        }
        printf("\n");
        return;
    }
    for (int i = 0; i < n - 1; i++) {
        if (a[i] == 0 && a[i + 1] == 1) {
            for (int j = 1; j <= i + 1; j++) {
                printf("%d ", j);
            }
            printf("%d ", n + 1);
            for (int j = i + 2; j <= n; j++) {
                printf("%d ", j);
            }
            printf("\n");
            return;
        }
    }
    printf("-1\n");
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
