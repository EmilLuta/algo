#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

long long arrangements(int n, int m, vector<int>& factorial) {
    int x = factorial[n];
    if (x < factorial[n - m]) {
        x += MOD;
    }
    return (x - factorial[n - m]) % MOD;
}

int main() {
    int n, x, pos;
    scanf("%d%d%d", &n, &x, &pos);
    long long answer = 0;
    vector<int> factorial(n, 1);
    for (int i = 2; i <= 1000; i++) {
        factorial[i] = ((long long)factorial[i - 1] * i) % MOD;
    }
    int left = 0, right = n, s = 0, b = 0;
    vector<pair<int, int>> opts;
    while (left < right) {
        int middle = (left + right) / 2;
        if (pos == middle) {
            break;
        }
        if (pos < middle) {
            opts.push_back({middle, 1});
            b++;
            right = middle;
        } else {
            opts.push_back({middle, -1});
            s++;
            left = middle + 1;
        }
    }
    for (int i = 0; i < opts.size(); i++) {
        printf("for pos %d we need %s\n", opts[i].first, opts[i].second == 1 ? "bigger" : "smaller");
    }
    int need_b = b;
    int need_s = s;
    int all_b = n - x;
    int all_s = x - 1;
    if (need_b > all_b || need_s > all_s) {
        printf("0\n");
        return 0;
    }
    if (need_b == 0 && need_s == 0) {
        printf("%lld\n", factorial[n - 1]);
        return 0;
    }
    long long z = 1;
    if (need_b > 0) {
        for (int i = need_b + 1; i <= all_b; i++) {
            z *= i;
            z %= MOD;
        }
    }
    long long y = 1;
    if (need_s > 0) {
        for (int i = need_s + 1; i <= all_s; i++) {
            y *= i;
            y %= MOD;
        }
    }
    printf("%lld\n", ((z * y) % MOD * factorial[n - 1 - need_s - need_b]) % MOD);
    /* printf("%lld\n", ((arrangements(all_b, need_b, factorial) * arrangements(all_s, need_s, factorial) % MOD) * factorial[n - 1 - need_s - need_b]) % MOD); */
    /* printf("arr(5, 2) == %d\n", arrangements(5, 2, factorial)); */
    /* printf("got to the end!\ncalling arrangement(%d, %d) * arrangement(%d, %d) * factorial[%d]\n", n - x, b, x - 1, s, n - s - b - 1); */
    /* if (s == 0 && b == 0) { */
    /*     printf("%lld\n", factorial[n - 1]); */
    /* } else { */
    /*     printf("%lld\n", ((arrangements(n - x, b, factorial) * arrangements(x - 1, s, factorial) % MOD) * factorial[n - s - b] % MOD)); */
    /* } */
}
