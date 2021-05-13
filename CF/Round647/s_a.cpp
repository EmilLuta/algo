#include <bits/stdc++.h>

using namespace std;

long long no_trailing_zeros(long long a) {
    while (a % 2 == 0) {
        a /= 2;
    }
    return a;
}

void solve() {
    long long a, b;
    scanf("%lld%lld", &a, &b);
    if (a > b) {
        swap(a, b);
    }
    if (no_trailing_zeros(a) != no_trailing_zeros(b)) {
        printf("-1\n");
        return;
    }
    int answer = 0;
    b /= a;
    while (b >= 8) {
        answer++;
        b /= 8;
    }
    if (b > 1) {
        answer += 1;
    }
    printf("%d\n", answer);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
    return 0;
}
