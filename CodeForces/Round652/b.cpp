#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    string s;
    cin >> s;
    bool only_zero = true, only_one = true;
    for (int i = 0; i < n; i++) {
        if (s[i] != '0') {
            only_zero = false;
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        if (s[i] != '1') {
            only_one = false;
            break;
        }
    }
    if (only_zero || only_one) {
        cout << s << '\n';
        return;
    }
    int z_i = 0, o_i = n - 1;
    while (s[z_i] == '0') {
        z_i++;
    }
    while (s[o_i] == '1') {
        o_i --;
    }
    if (o_i == n - 1 && z_i == 0) {
        cout << "0\n";
        return;
    }
    string answer = "";
    if (z_i - o_i != 1) {
        z_i++;
    }
    for (int i = 0; i < z_i; i++) {
        answer.push_back('0');
    }
    for (int i = o_i + 1; i < n; i++) {
        answer.push_back('1');
    }
    cout << answer << '\n';
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
