#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long p, q;
    scanf("%lld%lld", &p, &q);
    int i = 1;
    long long x = p;
    while (true) {
        x = p / i;
        if (p % x == 0 && x % q != 0) {
            printf("%lld\n", x);
            return;
        }
        i++;
        while (p % i != 0) {
            i++;
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
