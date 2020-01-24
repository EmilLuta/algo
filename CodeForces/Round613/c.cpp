#include <bits/stdc++.h>

using namespace std;

int main() {
    long long x;
    scanf("%lld", &x);
    long long sq = sqrt(x);
    for (int i = 1; i < sq; i++) {
        long long low = sq - i;
        long long high = sq + i;
        if (high % low == 0) {
            continue;
        }
        if (x % high == 0) {
            printf("%lld %lld", high, x / high);
            return 0;
        }
        if (x % low == 0) {
            printf("%lld %lld", low, x / low);
            return 0;
        }
    }
    printf("%lld %lld", 1, x);
}
