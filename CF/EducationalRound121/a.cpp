#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    cout << s << endl;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
