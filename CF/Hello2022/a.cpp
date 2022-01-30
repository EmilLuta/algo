#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    scanf("%d%d", &n, &k);
    if ((n + 1) / 2 < k) {
        printf("-1\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i % 2 == 0 && i == j && k > 0) {
                printf("R");
                k--;
                continue;
            }
            printf(".");
        }
        printf("\n");
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
