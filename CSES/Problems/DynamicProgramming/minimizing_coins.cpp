#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x;
    scanf("%d%d", &n, &x);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    vector<int> dp(x + 1, x * 2);
    dp[0] = 0;
    for (int s = 0; s <= x; s++) {
        for (int i = 0; i < n; i++) {
            int target = s + a[i];
            if (target <= x) {
                dp[target] = min(dp[target], dp[s] + 1);
            }
        }
    }
    if (dp[x] == x * 2) {
        printf("-1\n");
    } else {
        printf("%d\n", dp[x]);
    }
}
