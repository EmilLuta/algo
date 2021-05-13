#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        if (x == y && y == z) {
            printf("YES\n%d %d %d\n", x, y, z);
            continue;
        }
        if (x == y && z < y) {
            printf("YES\n%d %d %d\n", x, z, z);
            continue;
        }
        if (x == z && y < z) {
            printf("YES\n%d %d %d\n", x, y, y);
            continue;
        }
        if (y == z && x < z) {
            printf("YES\n%d %d %d\n", y, x, x);
            continue;
        }
        printf("NO\n");
    }
}
