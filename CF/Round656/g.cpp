#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        int n;
        scanf("%d", &n);
        map<int, int> a, b, c;
        int ok = true;
        for (int i = 0; i < 2 * n; i++) {
            int x;
            scanf("%d", &x);
            if (i < n) {
                a[x]++;
            } else {
                b[x]++;
            }
            c[x]++;
            if (c[x] > 2) {
                ok = false;
            }
        }
        if (!ok) {
            printf("-1\n");
            continue;
        }
        if (a.size() == n) {
            printf("0\n\n");
            continue;
        }
    }
}
