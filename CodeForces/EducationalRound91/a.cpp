#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < n - 1; i++) {
        if (a[i - 1] < a[i] && a[i] > a[i + 1]) {
            printf("YES\n");
            printf("%d %d %d\n", i, i + 1, i + 2);
            return;
        }
    }
    printf("NO\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
