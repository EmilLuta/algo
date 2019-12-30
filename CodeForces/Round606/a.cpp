#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        int n;
        scanf("%d", &n);
        int x = n, c = 0;
        while (x > 0) {
            x /= 10;
            c += 1;
        }
        /* printf("c = %d\n", c); */
        int o = (c - 1) * 9;
        int z = 0;
        int digit = n / ((int)pow(10, c - 1));
        for (int i = 0; i < c; i++) {
            z += pow(10, i) * digit;
        }
        /* printf("z = %d\n", z); */
        /* printf("digit = %d\n", digit); */
        o += digit;
        if (z > n) {
            o--;
        }
        printf("%d\n", o);
    }
}
