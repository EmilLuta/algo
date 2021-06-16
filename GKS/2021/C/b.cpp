#include <bits/stdc++.h>

using namespace std;

void solve(int t) {
    long long g;
    scanf("%lld", &g);
    int answer = 0;
    int h = 2 * g;
    for (long long k = 0; k * k <= h; k++) {
        int up = 2 * g - k * k - k;
        int down = 2 * (k + 1);
        if (up >= 0 && up % down == 0) {
            printf("k = %lld\n", k);
            answer++;
        }
    }
    printf("Case #%d: %d\n", t, answer);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        solve(t);
    }
}
