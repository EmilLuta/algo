#include <bits/stdc++.h>

using namespace std;

// ios::sync_with_stdio(0);
// cin.tie(0);

# define deb_v(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << a[i] << " "; \
    cerr << ")\n";

# define deb(x) cerr << #x << " = " << x << "\n";

void solve(int t) {
    int n;
    scanf("%d", &n);
    if (n == 1) {
        printf("0\n");
        return;
    }
    if (n == 2) {
        printf("1\n");
        return;
    }
    if (n == 3) {
        printf("2\n");
        return;
    }
    if (n % 2 == 0) {
        printf("2\n");
        return;
    }
    if (n % 2 == 1) {
        printf("3\n");
        return;
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
