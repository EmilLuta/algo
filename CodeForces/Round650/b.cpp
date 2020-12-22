#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    int even = 0, odd = 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if (i % 2 == 0) {
            if (x % 2 != 0) {
                odd++;
            }
        } else {
            if (x % 2 == 0) {
                even++;
            }
        }
    }
    if (even != odd) {
        printf("-1\n");
        return;
    }
    printf("%d\n", even);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
