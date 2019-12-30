#include <bits/stdc++.h>

using namespace std;

const long long MOD = pow(10, 9) + 7;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    if (n < m) {
        swap(n, m);
    }
    vector<long long> fib (n + 1);
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i <= n; i++) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
    }
    printf("%lld\n", (fib[n] * 2 - fib[1] * 2 + fib[m] * 2) % MOD);
}
