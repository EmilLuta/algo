#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        int r, g, b;
        scanf("%d %d %d", &r, &g, &b);
        int x, y, z;
        if (r >= g && r >= b) {
            x = r;
            if (g > b) {
                y = g;
                z = b;
            } else {
                y = b;
                z = g;
            }
        } else if (g >= r && g >= b) {
            x = g;
            if (r > b) {
                y = r;
                z = b;
            } else {
                y = b;
                z = r;
            }
        } else {
            x = b;
            if (r > g) {
                y = r;
                z = g;
            } else {
                y = g;
                z = r;
            }
        }
        /* printf("x = %d, y = %d, z = %d\n", x, y, z); */
        if (x > y + z) {
            printf("%d\n", y + z);
        } else {
            printf("%d\n", (x + y + z) / 2);
        }
    }
}
