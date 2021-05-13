#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    long long s = 0;
    for (int i = 0; i < n;i ++) {
        int x;
        scanf("%d", &x);
        s += x;
    }
    if (s == m) {
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
