#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    int count = 0;
    for (int r = 0; r < n; r++) {
        string s;
        cin >> s;
        if (s[m - 1] == 'R') {
            count++;
        }
        if (r == n - 1) {
            for (int c = 0; c < m; c++) {
                if (s[c] == 'D') {
                    count++;
                }
            }
        }
    }
    printf("%d\n", count);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
