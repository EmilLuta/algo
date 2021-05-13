#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        int n, p, k;
        scanf("%d %d %d", &n, &p, &k);
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        int price = p;
        sort(a.begin(), a.end());
        vector<int> dp(n);
        dp[0] = p - a[0];
        for (int i = 1; i < k - 1; i++) {
            dp[i] = dp[i - 1] - a[i];
        }
        dp[k - 1] = p - a[k - 1];
        for (int i = k; i < n; i++) {
            int x = max(dp[i - 1], dp[i - k]);
            dp[i] = x - a[i];
        }
        int answer = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] >= 0) {
                answer = i + 1;
            }
        }
        printf("%d\n", answer);
    }
}
