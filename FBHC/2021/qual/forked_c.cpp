#include <bits/stdc++.h>

using namespace std;

void solve(int t) {
    int n;
    scanf("%d", &n);
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<int, int> counter_r;
    map<int, int> counter_c;
    for (int c = 0; c < n; c++) {
        int need = 0;
        bool can = true;
        for (int r = 0; r < n; r++) {
            if (a[r][c] == 'O') {
                can = false;
                break;
            }
            if (a[r][c] == '.') {
                need++;
            }
        }
        if (can) {
            counter_r[need]++;
        }
    }
    for (int r = 0; r < n; r++) {
        int need = 0;
        int can = true;
        for (int c = 0; c < n; c++) {
            if (a[r][c] == 'O') {
                can = false;
                break;
            }
            if (a[r][c] == '.') {
                need++;
            }
        }
        if (can) {
            counter_c[need]++;
        }
    }
    if (counter_r.size() == 0 && counter_c.size() == 0) {
        printf("Case #%d: Impossible\n", t);
        return;
    }
    pair<int, int> row = *counter_r.begin();
    pair<int, int> col = *counter_c.begin();
    if (row.first == col.first) {
        printf("Case #%d: %d %d\n", t, row.first, max(row.second, col.second));
        return;
    }
    if (row.first > col.first) {
        printf("Case #%d: %d %d\n", t, col.first, col.second);
        return;
    }
    printf("Case #%d: %d %d\n", t, row.first, row.second);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
