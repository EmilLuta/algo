#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<vector<int>> rows(n, vector<int>(m));
    for (int r = 0; r < n; r++) {
        vector<int> row(m);
        for (int c = 0; c < m; c++) {
            scanf("%d", &row[c]);
        }
        rows[r] = row;
    }
    vector<int> col(n);
    for (int c = 0; c < m; c++) {
        for (int r = 0; r < n; r++) {
            scanf("%d", &col[r]);
        }
    }
    set<int> column_set(col.begin(), col.end());
    int column_index = -1;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (column_set.count(rows[r][c]) != 0) {
                column_index = c;
                break;
            }
        }
        if (column_index != -1) {
            break;
        }
    }
    vector<vector<int>> answer(n);
    int index = 0;
    for (int per_r = 0; per_r < n; per_r++) {
        for (int r = 0; r < n; r++) {
            if (rows[r][column_index] == col[per_r]) {
                answer[index] = rows[r];
                index++;
            }
        }
    }
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            printf("%d ", answer[r][c]);
        }
        printf("\n");
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
