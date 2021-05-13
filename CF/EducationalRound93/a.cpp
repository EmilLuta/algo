#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    if (a[0] + a[1] <= a[n - 1]) {
        printf("1 2 %d\n", n);
        return;
    }
    printf("-1\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
