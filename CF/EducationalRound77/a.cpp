#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int c, sum;
        scanf("%d %d", &c, &sum);
        int d = sum / c;
        int r = sum % c;
        long long out;
        if (r == 0) {
            out = (long)c * (long)((long)d * (long)d);
        } else {
            long start = (long)(c - r) * ((long)d * (long)d);
            out = start + (long)(r) * ((long)(d + 1) * (long)(d + 1));
        }
        printf("%lld\n", out);
    }
}
