#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int min_r = 10, min_c = 10;
    bool possible = true;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (a[r][c] == 'R') {
                if (r <= min_r && c <= min_c) {
                    min_r = r;
                    min_c = c;
                    possible = true;
                }
                if ((r < min_r && c > min_c) || (r > min_r && c < min_c)) {
                    possible = false;
                }
            }
        }
    }
    if (possible) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        solve();
        t--;
    }
}
