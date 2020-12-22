#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, s = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        if (i < n) {
            int x;
            scanf("%d", &x);
            s -= x;
        }
        s += i;
    }
    printf("%d\n", s);
}
