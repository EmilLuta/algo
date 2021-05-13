#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    scanf("%d%d", &n, &k);
    string s;
    cin >> s;
    if (k * 2 == n) {
        cout << "NO\n";
        return;
    }
    if (k == 0) {
        cout << "YES\n";
        return;
    }
    for (int i = 0; i < k; i++) {
        if (s[i] != s[n - i - 1]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
