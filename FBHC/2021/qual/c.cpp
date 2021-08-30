#include <bits/stdc++.h>

using namespace std;

void solve(int t) {
    int n;
    scanf("%d", &n);
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<int, int> counter;
    for (int c = 0; c < n; c++) {
        int need = 0;
        bool can = true;
        int dot_row = -1;
        for (int r = 0; r < n; r++) {
            if (a[r][c] == 'O') {
                can = false;
                break;
            }
            if (a[r][c] == '.') {
                need++;
                dot_row = r;
            }
        }
        if (can) {
            if (need == 1) {
                int dots_on_col = 0;
                for (int x = 0; x < n; x++) {
                    if (a[dot_row][x] == '.') {
                        dots_on_col++;
                    }
                }
                if (dots_on_col == 1) {
                    a[dot_row][c] = 'O';
                }
            }
            counter[need]++;
        }
    }
    for (int r = 0; r < n; r++) {
        int need = 0;
        int can = true;
        int dot_col = -1;
        for (int c = 0; c < n; c++) {
            if (a[r][c] == 'O') {
                can = false;
                break;
            }
            if (a[r][c] == '.') {
                need++;
                dot_col = c;
            }
        }
        if (can) {
            counter[need]++;
        }
    }
    if (counter.size() == 0) {
        printf("Case #%d: Impossible\n", t);
        return;
    }
    pair<int, int> p = *counter.begin();
    printf("Case #%d: %d %d\n", t, p.first, p.second);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
