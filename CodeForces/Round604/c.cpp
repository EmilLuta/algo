#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        int n;
        scanf("%d", &n);
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        int m = n / 2;
        int i = 1;
        int g = 1;
        while (a[i] == a[i - 1] && i < n) {
            i++;
            g++;
        }
        if (m % 3 == 0) {
            if (g >= m / 3) {
                /* printf("shitty 0\n"); */
                printf("0 0 0\n");
                continue;
            }
        } else {
            if (g > m / 3) {
                /* printf("da 0\n"); */
                printf("0 0 0\n");
                continue;
            }
        }
        i++;
        int s = 1;
        while (s <= g && i < n) {
            i++;
            s++;
        }
        while (a[i] == a[i - 1] && i < n) {
            i++;
            s++;
        }
        if (m - (g + s) < g) {
            /* printf("shitter 0\n"); */
            printf("0 0 0\n");
            continue;
        }
        int b = 1;
        i++;
        while (i < m) {
            i++;
            b++;
        }
        while (a[i] == a[i - 1]) {
            i--;
            b--;
        }
        if (b <= g) {
            /* printf("shittiest 0\n"); */
            printf("0 0 0\n");
            continue;
        }
        printf("%d %d %d\n", g, s, b);
    }
}
