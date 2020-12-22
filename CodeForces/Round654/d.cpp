#include <bits/stdc++.h>

using namespace std;

void print_m(vector<vector<int>>& m, int n) {
    int min_r = n, max_r = 0, min_c = n, max_c = 0;
    for (int r = 0; r < n ; r++) {
        int curr_r = 0, curr_c = 0;
        for (int c = 0; c < n; c++) {
            if (m[r][c] == 1) {
                curr_r++;
            }
            if (m[c][r] == 1) {
                curr_c++;
            }
        }
        max_r = max(max_r, curr_r);
        max_c = max(max_c, curr_c);
        min_r = min(min_r, curr_r);
        min_c = min(min_c, curr_c);
    }
    int r_diff = max_r - min_r, c_diff = max_c - min_c;
    printf("%d\n", r_diff * r_diff + c_diff * c_diff);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d", m[i][j]);
        }
        printf("\n");
    }
}

void solve() {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<vector<int>> m(n, vector<int>(n, 0));
    int start = 0;
    int f = 1;
    if (k > n * n) {
        f = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                m[i][j] = 1;
            }
        }
    }
    while (k > 0) {
        for (int i = 0; i < n; i++) {
            m[i][(i + start) % n] = f;
            k--;
            if (k <= 0) {
                break;
            }
        }
        start++;
    }
    print_m(m, n);
    /* for (int i = 0; i < min(n, k); i++) { */
    /*     m[0][i] = 1; */
    /* } */
    /* k -= min(n, k); */
    /* for (int i = 1; i < min(n, k); i++) { */
    /*     m[i][0] = 1; */
    /* } */
    /* k -= min(n, k); */
    /* for (int i = 1; i < n; i++) { */
    /*     for (int j = 1; j < n; j++) { */
    /*         if (k <= 0) { */
    /*             print_m(m, n); */
    /*             return; */
    /*         } */
    /*         m[i][j] = 1; */
    /*         k--; */
    /*     } */
    /* } */
    /* print_m(m, n); */
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
