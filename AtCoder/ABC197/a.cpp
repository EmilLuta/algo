#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    char start = s[0];
    for (int i = 1 ; i < n; i++) {
        s[i - 1] = s[i];
    }
    s[n - 1] = start;
    cout << s << endl;
}
