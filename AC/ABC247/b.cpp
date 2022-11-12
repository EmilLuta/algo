#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<string> s(n), t(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> t[i];
    }
    for (int i = 0; i < n; i++) {
        bool found_first = false, found_second = false;
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            if (s[i] == s[j] || s[i] == t[j]) {
                found_first = true;
            }
            if (t[i] == s[j] || t[i] == t[j]) {
                found_second = true;
            }
        }
        if (found_first && found_second) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
}
