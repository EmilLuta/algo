#include <bits/stdc++.h>

using namespace std;

// ios::sync_with_stdio(0);
// cin.tie(0);

# define deb_v(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << item << " "; \
    cerr << ")\n";

# define deb(x) cerr << #x << " = " << x << "\n";

# define deb_v_p(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << "(" << item.first << ", " << item.second << ") "; \
    cerr << ")\n";

void solve(int t) {
    int n;
    scanf("%d", &n);
    int x_f = -1, x_s = -1, y_f = -1, y_s = -1;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] == '*') {
                if (x_f == -1) {
                    x_f = j;
                    y_f = i;
                } else {
                    x_s = j;
                    y_s = i;
                }
            }
        }
    }
    int xx_f, xx_s, yy_f, yy_s;
    if (x_f == x_s) {
        xx_f = x_f == 0 ? 1 : 0;
        yy_f = y_f;
        xx_s = x_f == 0 ? 1 : 0;
        yy_s = y_s;
    } else if (y_f == y_s) {
        xx_f = x_f;
        yy_f = y_f == 0 ? 1 : 0;
        xx_s = x_s;
        yy_s = y_s == 0 ? 1 : 0;
    } else {
        xx_f = x_f;
        yy_f = y_s;
        xx_s = x_s;
        yy_s = y_f;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((x_f == j && y_f == i) || (x_s == j && y_s == i) || (xx_f == j && yy_f == i) || (xx_s == j && yy_s == i)) {
                printf("*");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
