#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        string s;
        cin >> s;
        int n = s.size();
        if (n == 1) {
            printf("a\n");
            continue;
        }
        for (int i = 1; i < n - 1; i++) {
            if (s[i] == '?') {
                if (s[i - 1] != 'a' && s[i + 1] != 'a') {
                    s[i] = 'a';
                } else if (s[i - 1] != 'b' && s[i + 1] != 'b') {
                    s[i] = 'b';
                } else {
                    s[i] = 'c';
                }
            }
        }
        if (s[n - 1] == '?') {
            if (s[n - 2] != 'a') {
                s[n - 1] = 'a';
            } else if (s[n - 2] != 'b') {
                s[n - 1] = 'b';
            } else {
                s[n - 1] = 'c';
            }
        }
        if (s[0] == '?') {
            if (s[1] != 'a') {
                s[0] = 'a';
            } else if (s[1] != 'b') {
                s[0] = 'b';
            } else {
                s[1] = 'c';
            }
        }
        bool wrong = false;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                printf("-1\n");
                wrong = true;
                break;
            }
        }
        if (!wrong) {
            cout << s << "\n";
        }
    }
}
