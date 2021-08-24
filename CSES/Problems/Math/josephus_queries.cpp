#include <bits/stdc++.h>

using namespace std;

int main() {
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int n, k;
        scanf("%d%d", &n, &k);
        int half = n / 2;
        if (half >= k) {
            printf("%d\n", k * 2);
        } else {
            k -= half;
            printf("%d\n", k * 2 - 1);
        }
    }
}
