#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    int mini = 1e9 + 1, maxi = 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        mini = min(mini, x);
        maxi = max(maxi, x);
    }
    printf("%d\n", maxi - mini);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
