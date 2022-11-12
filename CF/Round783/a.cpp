#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    if (n > m) {
        swap(n, m);
    }
    if (n == 1 && m > 2) {
        printf("-1\n");
        return;
    }
    int to_double = m - 1;
    if (n % 2 == m % 2) {
        printf("%d\n", to_double * 2);
        return;
    }
    printf("%d\n", to_double * 2 - 1);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        solve();
    }
}
