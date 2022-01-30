#include <bits/stdc++.h>

using namespace std;

# define deb_v(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << item << " "; \
    cerr << ")\n";

# define deb(x) cerr << #x << " = " << x << "\n";

# define deb_v_p(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << "(" << item.first << ", " << item.second << ") "; \
    cerr << ")\n";

void solve(int t) {
    int n, m, R, C;
    scanf("%d%d%d%d", &n, &m, &R, &C);
    R--;
    C--;
    bool has_black = false;
    bool on_row = false;
    bool on_col = false;
    bool exact = false;
    for (int r = 0; r < n; r++) {
        string s;
        cin >> s;
        for (int c = 0; c < m; c++) {
            if (s[c] == 'B') {
                has_black = true;
                if (r == R) {
                    on_row = true;
                }
                if (c == C) {
                    on_col = true;
                }
                if (c == C && r == R) {
                    exact = true;
                }
            }
        }
    }
    if (!has_black) {
        printf("-1\n");
        return;
    }
    if (exact) {
        printf("0\n");
        return;
    }
    if (on_col || on_row) {
        printf("1\n");
        return;
    }
    printf("2\n");
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
