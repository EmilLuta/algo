#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, a;
    scanf("%d%d%d", &n, &k, &a);
    int result = (k % n + a - 1) % n;
    if (result == 0) {
        printf("%d\n", n);
    } else {
        printf("%d\n", result);
    }
}
