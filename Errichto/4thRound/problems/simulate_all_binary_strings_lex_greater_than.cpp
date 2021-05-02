#include <bits/stdc++.h>

using namespace std;

int n, k;

void rec(string& s, string& curr, int i, int ones, bool changed) {
    if (i == n) {
        if (ones == k) {
            cout << curr << endl;
        }
        return;
    }
    if (n - i < k - ones) {
        return;
    }
    if (changed || s[i] == '0') {
        curr[i] = '0';
        rec(s, curr, i + 1, ones, changed);
    }
    curr[i] = '1';
    ones++;
    if (s[i] == '0') {
        changed = true;
    }
    rec(s, curr, i + 1, ones, changed);
}

int main() {
    string s;
    cin >> s >> k;
    n = s.size();
    string curr(n, ' ');
    rec(s, curr, 0, 0, false);
}
