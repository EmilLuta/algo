#include <stdio.h>

int main() {
    int n, m, d, c = 0;
    scanf("%d%d", &n, &m);
    if (m % n != 0) {
        printf("-1");
        return 0;
    }
    d = m / n;
    while (d % 2 == 0) {
        d /= 2;
        c++;
    }
    while (d % 3 == 0) {
        d /= 3;
        c++;
    }
    if (d == 1) {
        printf("%d", c);
        return 0;
    }
    printf("-1");
    return 0;
}