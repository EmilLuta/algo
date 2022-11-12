#include <bits/stdc++.h>

using namespace std;

int main() {
    ofstream fout("248.out");
    ifstream fin("248.in");
    int n;
    fin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        fin >> a[i];
    }
    vector<vector<int>> dp(n, vector<int>(n, -1));
    int answer = 0;
    for (int len = 0; len < n; len++) {
        for (int l = 0; l < n - len; l++) {
            int r = l + len;
            if (l == r) {
                dp[l][r] = a[l];
            }
            for (int mid = l; mid < r; mid++) {
                if (dp[l][mid] == dp[mid + 1][r]) {
                    dp[l][r] = max(dp[l][r], dp[l][mid] + 1);
                }
            }
            /* cout << "Looking at range [" << l << ", " << r << "], got " << dp[l][r] << "\n"; */
            answer = max(answer, dp[l][r]);
        }
    }
    fout << answer << endl;
}
