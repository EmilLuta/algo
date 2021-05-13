#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b;
    scanf("%d%d", &a, &b);
    if (a > b) {
        swap(a, b);
    }
    if (2 * a <= b) {
        printf("%d\n", a);
        return;
    }
    printf("%d\n", (a + b) / 3);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
