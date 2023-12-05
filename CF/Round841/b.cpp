#include <bits/stdc++.h>

using namespace std;

long long MOD = 1e9 + 7;

void solve() {
    int n;
    scanf("%d", &n);
    long long answer = 1;
    for (int i = 2; i <= n; i++) {
        answer += ((long long)i * i) % MOD;
        answer %= MOD;
        answer += ((long long)(i - 1) * i) % MOD;
        answer %= MOD;
    }
    printf("%lld\n", (answer * 2022) % MOD);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        solve();
        t--;
    }
}
