#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x;
    scanf("%d%d", &n, &x);
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    for (int i = 0; i < n; i++) {
        if (a[i] + b[i] > x) {
            printf("No\n");
            return;
        }
    }
    printf("Yes\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
