#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    printf("%d\n", max(a + b, c + d));
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
