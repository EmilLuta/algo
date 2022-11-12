#include <bits/stdc++.h>

using namespace std;

void solve(int t) {
    string s;
    cin >> s;
    int n = s.size();
    vector<bool> dup(n, false);
    for (int i = 0; i < n - 1; i++) {
        int start = i;
        while (i < n - 1 && s[i] == s[i + 1]) {
            i++;
        }
        if (i == n - 1) {
            break;
        }
        if (s[i] < s[i + 1]) {
            for (int j = start; j <= i; j++) {
                dup[j] = true;
            }
        }
    }
    string out;
    for (int i = 0; i < n; i++) {
        if (dup[i]) {
            out += s[i];
        }
        out += s[i];
    }
    cout << "Case #" << t << ": " << out << endl;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
