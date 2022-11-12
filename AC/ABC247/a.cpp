#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    string out = "0000";
    int n = s.size();
    for (int i = 0; i < n - 1; i++) {
        out[i + 1] = s[i];
    }
    cout << out << endl;
}
