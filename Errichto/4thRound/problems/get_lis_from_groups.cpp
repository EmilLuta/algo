#include <bits/stdc++.h>

using namespace std;

int lis(vector<vector<int>>& a) {
    vector<int> dp;
    int n = a.size();
    for (int i = 0; i < n; i++) {
        map<int, int> to_add;
        for (int x : a[i]) {
            int ge_index = lower_bound(dp.begin(), dp.end(), x) - dp.begin();
            to_add[x] = ge_index;
        }
        for (pair<int, int> p : to_add) {
            if (p.second == (int)dp.size()) {
                dp.push_back(p.first);
            } else {
                dp[p.second] = min(dp[p.second], p.first);
            }
        }
    }
    return dp.size();
}

int main() {
    int n;
    scanf("%d", &n);
    vector<vector<int>> a(n, vector<int>());
    for (int i = 0; i < n; i++) {
        int m;
        scanf("%d", &m);
        a[i].resize(m);
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    printf("%d\n", lis(a));
}
