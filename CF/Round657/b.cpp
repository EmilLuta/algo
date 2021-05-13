#include<bits/stdc++.h>

using namespace std;

void solve() {
    long long l, r, m;
    scanf("%lld%lld%lld", &l, &r, &m);
    long long range = r - l;
    for (long long n = 1; n * n <= m; n++) {
        long long mod = m % n;
        vector<long long> opts(2);
        opts[0] = n;
        opts[1] = m / n;
        for (long long a : opts) {
            long long start = a;
            while (true) {
                long long prod = n * a;
                if (prod > m + range) {
                    break;
                }
                long long c = l + prod - m;
                printf("considering n = %lld, a = %lld, b = %lld, c = %lld\n", n, a, l, c);
                if (a >= l && a <= r && c >= l && c <= r) {
                    printf("%lld %lld %lld %lld\n", n, a, l, c);
                }
                a++;
            }
            a = start;
            while (true) {
                long long prod = n * a;
                if (prod < m - range) {
                    break;
                }
                long long b = l + prod - m;
                printf("considering n = %lld, a = %lld, b = %lld, c = %lld\n", n, a, b, l);
                if (a >= l && a <= r && b >= l && b <= r) {
                    printf("%lld %lld %lld %lld\n", n, a, b, l);
                }
                a--;
            }
        }
    }
    printf("---\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
