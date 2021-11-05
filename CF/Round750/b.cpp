#include <bits/stdc++.h>

using namespace std;

long long pow_2[61];

void solve() {
    int n;
    scanf("%d", &n);
    vector<long long> a(n);
    long long answer = 0;
    long long ones = 0;
    long long zeros = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if (a[i] == 1) {
            ones++;
        }
        if (a[i] == 0) {
            zeros++;
        }
    }
    answer = ones * pow_2[zeros];
    printf("%lld\n", answer);
}

int main() {
    int t;
    scanf("%d", &t);
    pow_2[0] = 1;
    for (int i = 1; i <= 60; i++) {
        pow_2[i] = pow_2[i - 1] * 2;
    }
    while (t > 0) {
        t--;
        solve();
    }
}
