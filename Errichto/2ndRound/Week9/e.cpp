#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    int answer = 0;
    for (int col = 0; col < m; col++) {
        vector<int> matches(n);
        for (int row = 0; row < n; row++) {
            if ((a[row][col] - (col + 1)) % m == 0) {
                int formula = (a[row][col] - (col + 1)) / m;
                if (!(0 <= formula && formula < n)) {
                    continue;
                }
                int shift = row - formula;
                if (shift < 0) {
                    shift = n + shift;
                }
                assert(0 <= shift && shift < (int) matches.size());
                matches[shift]++;
            }
        }
        int best = INT_MAX;
        for (int shift = 0; shift < n; shift++) {
            best = min(best, shift + n - matches[shift]);
        }
        assert(best != INT_MAX);
        answer += best;
    }
    printf("%d\n", answer);
}
