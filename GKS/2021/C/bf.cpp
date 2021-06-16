#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        long long g;
        scanf("%lld", &g);
        for (long long i = 1; i <= g; i++) {
            long long x = i;
            long long j = i + 1;
            while (x < g) {
                x += j;
                j++;
            }
            if (x == g) {
                printf("got %lld numbers, start = %lld, end = %lld, value = %lld\n", j - i, i, j - 1, g);
            }
        }
    }
}
