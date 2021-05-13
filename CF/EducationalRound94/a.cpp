#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    string s;
    cin >> s;
    string answer = "";
    for (int i = 0; i < n; i++) {
        answer += s[n - 1];
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
