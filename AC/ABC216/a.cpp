#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int i = 0;
    while (s[i] != '.') {
        cout << s[i];
        i++;
    }
    if ('0' <= s[i + 1] && s[i + 1] <= '2') {
        cout << "-\n";
    }
    if ('3' <= s[i + 1] && s[i + 1] <= '6') {
        cout << "\n";
    }
    if ('7' <= s[i + 1] && s[i + 1] <= '9') {
        cout << "+\n";
    }
}
