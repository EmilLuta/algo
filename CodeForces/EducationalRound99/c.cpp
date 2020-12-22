#include <bits/stdc++.h>

using namespace std;

# define deb_v(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << a[i] << " "; \
    cerr << ")\n";

# define deb(x) cerr << #x << " = " << x << "\n";

void solve(int t) {
    int a, b;
    scanf("%d%d", &a, &b);
    if (b == 0) {
        printf("%d 0\n", a);
        return;
    }
    if (a == 0) {
        printf("0 %d\n", b);
        return;
    }
    if (a >= b) {
        printf("%d %d\n", a - 1, b);
        return;
    }
    if (a < b) {
        printf("%d %d\n", a - 1, b);
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
