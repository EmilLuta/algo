#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a[4];
    scanf("%d%d%d%d", &a[0], &a[1], &a[2], &a[3]);
    int c = 1;
    while (c >= 0) {
        int odds = 0;
        for (int i = 0; i < 4; i++) {
            if (a[i] % 2 == 1) {
                odds++;
            }
            if (a[i] < 0) {
                printf("NO\n");
                return;
            }
            a[i]--;
        }
        a[3] += 4;
        if (odds <= 1) {
            printf("YES\n");
            return;
        }
        c--;
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
