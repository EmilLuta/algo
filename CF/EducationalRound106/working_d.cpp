#include <bits/stdc++.h>

using namespace std;

const int N = 2e7 + 13;

int main() {
    vector<int> mind(N, -1), val(N);
    mind[1] = 1;
    for (int i = 2; i < N; i++) {
        if (mind[i] == -1) {
            for (int j = i; j < N; j += i) {
                if (mind[j] == -1) {
                    mind[j] = i;
                }
            }
        }
    }
    for (int i = 2; i < N; i++) {
        int j = i / mind[i];
        val[i] = val[j] + (mind[i] != mind[j]);
    }
    int t;
    scanf("%d", &t);
    while (t--) {
        int c, d, x;
        scanf("%d%d%d", &c, &d, &x);
        int ans = 0;
        for (int i = 1; i * i <= x; i++) {
            if (x % i != 0) {
                continue;
            }
            int k1 = x / i + d;
            if (k1 % c == 0) {
                ans += 1 << val[k1 / c];
            }
            if (i * i == x) {
                continue;
            }
            int k2 = i + d;
            if (k2 % c == 0) {
                ans += 1 << val[k2 / c];
            }
        }
        printf("%d\n", ans);
    }
}
