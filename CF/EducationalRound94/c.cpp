#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    string answer(n, '1');
    int x;
    scanf("%d", &x);
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            if (i - x >= 0) {
                answer[i - x] = '0';
            }
            if (i + x < n) {
                answer[i + x] = '0';
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            if (i - x >= 0 && answer[i - x] == '1') {
                continue;
            }
            if (i + x < n && answer[i + x] == '1') {
                continue;
            }
            printf("-1\n");
            return;
        }
    }
    cout << answer << endl;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
