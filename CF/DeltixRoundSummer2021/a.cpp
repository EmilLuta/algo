#include <bits/stdc++.h>

using namespace std;

void solve() {
    int c, d;
    scanf("%d%d", &c, &d);
    if (abs(c - d) % 2 == 1) {
        printf("-1\n");
        return;
    }
    if (c == d) {
        if (c == 0) {
            printf("0\n");
            return;
        }
        printf("1\n");
        return;
    }
    printf("2\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        solve();
        t--;
    }
}
