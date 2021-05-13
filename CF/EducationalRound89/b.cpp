#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x, m;
    scanf("%d%d%d", &n, &x, &m);
    int start = x, end = x;
    for (int i = 0; i < m; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        if (r < start || l > end) {
            continue;
        }
        start = min(start, l);
        end = max(end, r);
    }
    printf("%d\n", end - start + 1);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
