#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", 6 + (n - 1) * 2 + n);
    printf("0 0\n");
    printf("1 0\n");
    for (int i = 1; i <= n; i++) {
        printf("%d %d\n", i - 1, i);
        printf("%d %d\n", i, i);
        printf("%d %d\n", i + 1, i);
    }
    printf("%d %d\n", n, n + 1);
    printf("%d %d\n", n + 1, n + 1);
}
