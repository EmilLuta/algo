#include <stdio.h>
#include <stdlib.h>

long long min(long long a, long long b) {
    if (a > b) {
        return b;
    }
    return a;
}

int main() {
    int a[100000], dp[100000], n, k;;
    const int inf = 1e9;
    scanf("%d", &n);
    scanf("%d", &k);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        dp[i] = inf;
    }
    dp[0] = 0;
    for(int i = 1; i < n; i++){
        for(int j = 1; j < min(i, k) + 1; j++){
            dp[i] = min(dp[i], abs(a[i] - a[i - j]) + dp[i - j]);
        }
    }
    printf("%d\n", dp[n - 1]);
    return 0;
}