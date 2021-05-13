#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    bool ok = false;
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        if (b == c) {
            ok = true;
        }
    }
    if (ok && m % 2 == 0) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
