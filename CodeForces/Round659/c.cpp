#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    string a, b;
    cin >> a;
    cin >> b;
    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) {
            printf("-1\n");
            return;
        }
    }
    if (n == 1) {
        if (a[0] == b[0]) {
            printf("0\n");
        } else {
            printf("1\n");
        }
        return;
    }
    int groups_a = 0;
    int groups_b = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1] && a[i - 1] != b[i - 1]) {
            groups_a++;
        }
        if (b[i] != b[i - 1] && b[i - 1] != a[i - 1]) {
            groups_b++;
        }
    }
    if (a[n - 1] != a[n - 2] && a[n - 1] != b[n - 1]) {
        groups_a++;
    }
    if (b[n - 1] != b[n - 2] && b[n - 1] != a[n - 1]) {
        groups_b++;
    }
    printf("%d\n", min(groups_a, groups_b));
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
