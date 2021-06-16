#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int a[n][n];
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            scanf("%d", &a[r][c]);
        }
    }
    int h = k * k / 2 + 1;
    vector<int> vals;
    int answer = INT_MAX;
    for (int s_r = 0; s_r <= n - k; s_r++) {
        for (int s_c = 0; s_c <= n - k; s_c++) {
            for (int r = s_r; r < s_r + k; r++) {
                for (int c = s_c; c < s_c + k; c++) {
                    vals.push_back(a[r][c]);
                }
            }
            sort(vals.rbegin(), vals.rend());
            answer = min(answer, vals[h - 1]);
            vals.resize(0);
        }
    }
    printf("%d\n", answer);
}
