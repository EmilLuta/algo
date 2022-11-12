#include <bits/stdc++.h>

using namespace std;

void solve() {
    int l1, r1, l2, r2;
    scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
    if (r1 < l2 || r2 < l1) {
        printf("%d\n", l1 + l2);
        return;
    }
    printf("%d\n", max(l1, l2));
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        solve();
        t--;
    }
}
