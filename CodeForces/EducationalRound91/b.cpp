#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        string a;
        cin >> a;
        int n = a.size();
        int r = 0, s = 0, p = 0;
        for (int i = 0; i < n; i++) {
            switch (a[i]) {
                case 'R':
                    r++;
                    break;
                case 'S':
                    s++;
                    break;
                case 'P':
                    p++;
                    break;
            }
        }
        char c;
        if (r >= p && r >= s) {
            c = 'P';
        } else if (p >= r && p >= s) {
            c = 'S';
        } else if (s >= r && s >= p) {
            c = 'R';
        }
        string out = "";
        for (int i = 0; i < n; i++) {
            out += c;
        }
        out += '\n';
        cout << out;
    }
}
