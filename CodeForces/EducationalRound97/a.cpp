#include <bits/stdc++.h>

using namespace std;

void solve() {
    int l, r;
    scanf("%d%d", &l, &r);
    if (r >= l * 2) {
        printf("NO\n");
    } else {
        printf("YES\n");
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
