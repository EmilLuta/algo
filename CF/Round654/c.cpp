#include <bits/stdc++.h>

using namespace std;


int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        long long a, b, n, m;
        scanf("%lld%lld%lld%lld", &a, &b, &n, &m);
        if (min(a, b) < m || (a + b) < (n + m)) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }
}
