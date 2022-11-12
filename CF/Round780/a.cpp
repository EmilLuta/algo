#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b;
    scanf("%d%d", &a, &b);
    if (a == 0) {
        printf("1\n");
        return;
    }
    printf("%d\n", 2 * b + a + 1);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        solve();
        t--;
    }
}
