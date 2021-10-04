#include <bits/stdc++.h>

using namespace std;

void print_dp(map<int, long long>& dp) {
    printf("dp = {\n");
    for (auto p : dp) {
        printf("\tfinish at %d with reward = %lld\n", p.first, p.second);
    }
    printf("}\n");
}

int main() {
    int n;
    scanf("%d", &n);
    vector<pair<pair<int, int>, int>> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &a[i].first.second, &a[i].first.first, &a[i].second);
    }
    sort(a.begin(), a.end());
    map<int, long long> dp;
    long long last = 0;
    for (int i = 0; i < n; i++) {
        int start = a[i].first.second;
        int end = a[i].first.first;
        int val = a[i].second;
        auto it = dp.lower_bound(start);
        long long curr = 0;
        if (it != dp.begin()) {
            it--;
            curr = (*it).second;
        }
        long long new_value = max(last, curr + val);
        dp[end] = max(dp[end], new_value);
        last = dp[end];
    }
    long long answer = 0;
    for (auto x : dp) {
        answer = max(answer, x.second);
    }
    printf("%lld\n", answer);
}
