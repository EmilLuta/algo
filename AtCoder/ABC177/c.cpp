#include <bits/stdc++.h>

using namespace std;

int MOD = 1e9 + 7;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    vector<long long> suff(n + 1, 0);
    for(int i = n - 1; i >= 0; i--) {
        suff[i] = suff[i + 1] + a[i];
    }
    long long answer = 0;
    for (int i = 0; i < n; i++) {
        answer = answer + (a[i] % MOD) * (suff[i + 1] % MOD) % MOD;
        answer %= MOD;
    }
    printf("%lld\n", answer);
}
