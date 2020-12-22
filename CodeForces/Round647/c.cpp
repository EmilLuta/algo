#include <bits/stdc++.h>

using namespace std;

int main() {
    int N = 61;
    map<long long, long long> value_at_power;
    vector<long long> powers(N);
    for (int i = 0; i < N; i++) {
        long long p = 1LL << i;
        value_at_power[p] = (p << 1) - 1;
        powers[i] = p;
    }
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        long long n;
        scanf("%lld", &n);
        long long answer = 0;
        while (n != 0) {
            for (int i = 0; i < N; i++) {
                if (powers[i] > n) {
                    n -= powers[i - 1];
                    answer += value_at_power[powers[i - 1]];
                    break;
                }
            }
        }
        printf("%llu\n", answer);
    }
}
