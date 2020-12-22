#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007;

long long pow_mod(int x) {
    long long answer = 1;
    for (int i = 0; i < x; i++) {
        answer = ((answer * 3) % MOD);
    }
    return answer;
}

void solve() {
    long long n;
    scanf("%lld", &n);
    n -= 3;
    long long answer = (pow_mod(n) + 1) / 2;
    n -= 2;
    while (n >= 0) {
        answer = (answer + pow_mod(n)) % MOD;
        n -= 2;
        printf("n = %d\n", n);
    }
    printf("%lld\n", (answer * 4) % MOD);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
