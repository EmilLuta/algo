#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n;
    scanf("%lld", &n);
    long long answer = n * (n + 1) / 2;
    long long p_t = 1;
    while (p_t <= n) {
        answer -= 2 * p_t;
        p_t <<= 1;
    }
    printf("%lld\n", answer);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
