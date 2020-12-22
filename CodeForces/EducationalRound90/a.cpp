#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long a, b, c;
    scanf("%lld%lld%lld", &a, &b, &c);
    long long f = -1, s = -1;
    if (a < c) {
        f = c / a;
        if (c % a == 0) {
            f--;
        }
    }
    if (c / b < a) {
        s = b;
    }
    printf("%lld %lld\n", f, s);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
