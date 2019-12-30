#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        int r, b, k;
        scanf("%d %d %d", &r, &b, &k);
        if (r < b) {
            swap(r, b);
        }
        int x = r / b;
        int g = __gcd(r, b);
        if (r % b == 0) {
            x--;
        }
        if (g == 1) {
            x++;
        }
        if (x < k) {
            printf("OBEY\n");
        } else {
            printf("REBEL\n");
        }
    }
}
