#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    string out = "";
    for (int i = 0; i < 6; i++) {
        out += s[i % n];
    }
    cout << out << endl;
}
