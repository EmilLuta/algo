#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, u, v;
    scanf("%d%d%d", &n, &u, &v);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    bool all_the_same = true;
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) {
            all_the_same = false;
        }
    }
    if (all_the_same) {
        printf("%d\n", v + min(v, u));
        return;
    }
    bool tied = true;
    for (int i = 1; i < n; i++) {
        if (abs(a[i] - a[i - 1]) > 1) {
            tied = false;
        }
    }
    if (tied) {
        printf("%d\n", min(u, v));
    } else {
        printf("0\n");
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
