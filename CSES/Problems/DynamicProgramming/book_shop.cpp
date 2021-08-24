#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x;
    scanf("%d%d", &n, &x);
    vector<int> prices(n);
    vector<int> pages(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &prices[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    for (int i = 0; i < n; i++) {
        for (int s = 0; s <= x; s++) {
            dp[i + 1][s] = max(dp[i + 1][s], dp[i][s]);
            int cost = s + prices[i];
            if (cost <= x) {
                dp[i + 1][cost] = max(dp[i + 1][cost], dp[i][s] + pages[i]);
            }
        }
    }
    printf("%d\n", dp[n][x]);
}
