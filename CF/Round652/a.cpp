#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        long long n;
        scanf("%lld", &n);
        if (n % 4 == 0) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
}
