#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> dp(n + 1, n * 2);
    dp[n] = 0;
    for (int i = n; i > 0; i--) {
        if (dp[i] == n * 2) {
            continue;
        }
        int x = i;
        while (x != 0) {
            int r = x % 10;
            if (i - r >= 0) {
                dp[i - r] = min(dp[i - r], dp[i] + 1);
            }
            x /= 10;
        }
    }
    printf("%d\n", dp[0]);
}
