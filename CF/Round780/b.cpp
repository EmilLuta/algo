#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a.begin(), a.end());
    if (n == 1) {
        if (a[n - 1] == 1) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
        return;
    }
    if (a[n - 1] - a[n - 2] <= 1) {
        printf("YES\n");
        return;
    }
    printf("NO\n");
    return;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
