#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x;
    scanf("%d%d", &n, &x);
    vector<int> a(n);
    long long s = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        s += a[i];
    }
    if (s % x != 0) {
        printf("%d\n", n);
        return;
    }
    int first = -1, last = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] % x != 0) {
            first = i;
            break;
        }
    }
    if (first == -1) {
        printf("-1\n");
        return;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] % x != 0) {
            last = i;
            break;
        }
    }
    printf("%d\n", max(n - first - 1, last));
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
