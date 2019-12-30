#include <stdio.h>

int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

int main() {
    int n, d = 0;
    scanf("%d", &n);
    int a[n + 1];
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if (a[i] != a[j]) {
                d = max(j - i, d);
            }
        }
    }
    printf("%d", d);
    return 0;
}
