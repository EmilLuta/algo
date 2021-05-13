#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    string out = "";
    out += s[0];
    for (int i = 1; i < n - 1; i += 2) {
        out += s[i];
    }
    out += s[n - 1];
    cout << out << '\n';
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
