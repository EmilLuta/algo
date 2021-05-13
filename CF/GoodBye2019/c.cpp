#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        int n;
        scanf("%d", &n);
        vector<int> a(n);
        long long s = 0;
        long long x = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            s += a[i];
            x ^= a[i];
        }
        if (s == 2 * x) {
            printf("0\n\n");
            continue;
        }
        long long a1 = x;
        long long a2 = s + x;
        printf("2\n");
        printf("%lld %lld\n", a1, a2);
    }
}
