#include <bits/stdc++.h>

using namespace std;

// ios::sync_with_stdio(0);
// cin.tie(0);

# define deb_v(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << item << " "; \
    cerr << ")\n";

# define deb(x) cerr << #x << " = " << x << "\n";

# define deb_v_p(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << "(" << item.first << ", " << item.second << ") "; \
    cerr << ")\n";

void solve(int t) {
    int a, b;
    scanf("%d%d", &a, &b);
    int n = a + b;
    string s;
    cin >> s;
    for (int i = 0; i < n / 2; i++) {
        if (s[i] == '0') {
            if (s[n - i - 1] == '1') {
                printf("-1\n");
                return;
            }
            if (s[n - i - 1] == '?') {
                s[n - i - 1] = '0';
            }
        }
        if (s[i] == '1') {
            if (s[n - i - 1] == '0') {
                printf("-1\n");
                return;
            }
            if (s[n - i - 1] == '?') {
                s[n - i - 1] = '1';
            }
        }
        if (s[n - i - 1] == '0') {
            if (s[i] == '1') {
                printf("-1\n");
                return;
            }
            if (s[i] == '?') {
                s[i] = '0';
            }
        }
        if (s[n - i - 1] == '1') {
            if (s[i] == '0') {
                printf("-1\n");
                return;
            }
            if (s[i] == '?') {
                s[i] = '1';
            }
        }
        if (s[i] == '0') {
            a--;
        }
        if (s[i] == '1') {
            b--;
        }
        if (s[n - i - 1] == '0') {
            a--;
        }
        if (s[n - i - 1] == '1') {
            b--;
        }
    }

    for (int i = 0; i < n / 2; i++) {
        if (s[i] == '?') {
            if (a > 1) {
                s[i] = '0';
                s[n - i - 1] = '0';
                a -= 2;
            } else if (b > 1) {
                s[i] = '1';
                s[n - i - 1] = '1';
                b -= 2;
            } else {
                printf("-1\n");
                return;
            }
        }
    }
    if (n % 2 == 1) {
        if (s[n / 2] == '?') {
            if (a == 1) {
                s[n / 2] = '0';
                a--;
            } else if (b == 1) {
                s[n / 2] = '1';
                b--;
            } else {
                printf("-1\n");
                return;
            }
        } else {
            if (s[n / 2] == '0') {
                a--;
            } else {
                b--;
            }
        }
    }
    if (a < 0 || b < 0) {
        printf("-1\n");
        return;
    }
    cout << s << "\n";
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
