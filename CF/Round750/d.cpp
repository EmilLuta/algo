#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int start = 0;
    if (n % 2 == 1) {
        start = 3;
        int x = a[0], y = a[1], z = a[2];
        if (x + y != 0) {
            printf("%d %d %d ", -z, -z, x + y);
        } else if (x + z != 0) {
            printf("%d %d %d ", -y, x + z, -y);
        } else {
            printf("%d %d %d ", y + z, -x, -x);
        }
    }
    for (int i = start; i < n; i += 2) {
        printf("%d %d ", -a[i + 1], a[i]);
    }
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        solve();
        t--;
    }
}
