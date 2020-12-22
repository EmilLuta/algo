#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int compute_inv_modulo(int a) {
    int answer = 1;
    int b = MOD - 2;
    while (b > 0) {
        if (b % 2 != 0) {
            answer = ((long long)answer * a) % MOD;
        }
        a = ((long long)a * a) % MOD;
        b /= 2;
    }
    return answer;
}

int main() {
    int n;
    scanf("%d", &n);
    int two_n = n * 2;
    vector<int> a(two_n);
    for (int i = 0; i < two_n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a.begin(), a.end());
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += abs(a[i] - a[two_n - i - 1]);
        sum %= MOD;
    }
    vector<int> inv_mod(n + 1);
    long long times = 1;
    for (int i = 1; i <= n; i++) {
        times = (times * (n + i)) % MOD;
        inv_mod[i] = compute_inv_modulo(i);
        times = (times * inv_mod[i]) % MOD;
        times %= MOD;
    }
    int answer = (times * sum) % MOD;
    printf("%d\n", answer);
}
