#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    if (n == 1) {
        printf("1\n");
        return 0;
    }
    if (n < 4) {
        printf("NO SOLUTION\n");
        return 0;
    }
    for (int i = 2; i <= n; i += 2) {
        printf("%d ", i);
    }
    for (int i = 1; i <= n; i += 2) {
        printf("%d ", i);
    }
    printf("\n");
}
