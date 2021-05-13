#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<string> s(n), t(m);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> t[i];
    }
    int q;
    scanf("%d", &q);
    string out;
    for (int i = 0; i < q; i++) {
        int y;
        scanf("%d", &y);
        y--;
        out += s[y % n];
        out += t[y % m];
        out += "\n";
    }
    cout << out;
}
