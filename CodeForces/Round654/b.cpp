#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        long long n, r;
        scanf("%lld%lld", &n, &r);
        if (n > r) {
            printf("%lld\n", r * (r + 1) / 2);
            continue;
        }
        printf("%lld\n", n * (n - 1) / 2 + 1);
    }
}
