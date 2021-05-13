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
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        vector<int>dp(n + 1, 1);
        for (int i = 2; i < n + 1; i++) {
            int j = 1;
            while (j * j <= i) {
                if (i % j == 0 && a[j - 1] < a[i - 1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
                int x = i / j;
                if (x != j) {
                    if (i % x == 0 && a[x - 1] < a[i - 1]) {
                        dp[i] = max(dp[i], dp[x] + 1);
                    }
                }
                j++;
            }
        }
        int answer = 0;
        for (int i = 0; i < n + 1; i++) {
            answer = max(answer, dp[i]);
        }
        printf("%d\n", answer);
    }
}
