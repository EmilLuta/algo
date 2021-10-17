#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> pref(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != 0) {
                pref[i][j] += pref[i - 1][j];
            }
            if (j != 0) {
                pref[i][j] += pref[i][j - 1];
            }
            if (j != 0 && i != 0) {
                pref[i][j] -= pref[i - 1][j - 1];
            }
            if (a[i][j] == '*') {
                pref[i][j]++;
            }
        }
    }
    for (int i = 0; i < q; i++) {
        int r1, c1, r2, c2;
        scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
        r1--;
        r2--;
        c1--;
        c2--;
        int answer = pref[r2][c2];
        if (r1 > 0) {
            answer -= pref[r1 - 1][c2];
        }
        if (c1 > 0) {
            answer -= pref[r2][c1 - 1];
        }
        if (r1 > 0 && c1 > 0) {
            answer += pref[r1 - 1][c1 - 1];
        }
        printf("%d\n", answer);
    }
}
