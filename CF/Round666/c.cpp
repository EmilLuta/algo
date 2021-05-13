#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    if (n == 1) {
        printf("1 1\n0\n1 1\n0\n1 1\n%d\n", -a[0]);
        return 0;
    }
    printf("1 1\n");
    printf("%d\n", -a[0]);
    a[0] = 0;
    printf("2 %d\n", n);
    for (int i = 1; i < n; i++) {
        printf("%lld ", (long long)(n - 1) * a[i]);
    }
    printf("\n");
    printf("1 %d\n", n);
    for (int i = 0; i < n; i++) {
        printf("%lld ", (long long)(-n) * a[i]);
    }
    printf("\n");
}
