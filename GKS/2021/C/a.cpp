#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

const int K = 27;
const int N = 100007;

int at_power[K][N];


void solve(int t) {
    int n, k;
    scanf("%d%d", &n, &k);
    string s;
    cin >> s;
    long long answer = 0;
    for (int i = 0; i < (n + 1) / 2; i++) {
        int left = n - (i + 1) * 2;
        int to_change = (left + 1) / 2;
        answer += (long long)(s[i] - 'a') * at_power[k][to_change] % MOD;
        answer %= MOD;
    }
    string possible(s.begin(), s.end());
    for (int i = 0; i < n / 2; i++) {
        possible[n - i - 1] = s[i];
    }
    if (possible < s) {
        answer++;
        answer %= MOD;
    }
    printf("Case #%d: %lld\n", t, answer);
}

int main() {
    for (int k = 0; k < K; k++) {
        at_power[k][0] = 1;
        for (int i = 1; i < N; i++) {
            at_power[k][i] = (long long)at_power[k][i - 1] * k % MOD;
        }
    }
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        solve(t);
    }
}
