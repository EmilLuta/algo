#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long a, b, x;
    scanf("%lld%lld%lld", &a, &b, &x);
    long long maxi = max(a, b);
    if (x > maxi) {
        printf("NO\n");
    } else {
        printf("YES\n");
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        solve();
        t--;
    }
}
