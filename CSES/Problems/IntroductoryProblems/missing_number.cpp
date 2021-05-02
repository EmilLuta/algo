#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    long long sum = (long long)n * (n + 1) / 2;
    for (int i = 0; i < n - 1; i++) {
        int x;
        scanf("%d", &x);
        sum -= x;
    }
    printf("%lld\n", sum);
}
