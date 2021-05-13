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
    int n;
    scanf("%d", &n);
    string s;
    cin >> s;
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            c++;
        }
    }
    if (s[0] == '0' || s[n - 1] == '0' || c % 2 == 1) {
        printf("NO\n");
        return;
    }
    int c_a = 1, c_b = 1;
    string a(n, '-'), b(n, '-');
    a[0] = '(';
    b[0] = '(';
    a[n - 1] = ')';
    b[n - 1] = ')';
    for (int i = 1; i < n - 1; i++) {
        if (s[i] == '0') {
            if (c_a > c_b) {
                a[i] = ')';
                c_a--;
                b[i] = '(';
                c_b++;
            } else {
                a[i] = '(';
                c_a++;
                b[i] = ')';
                c_b--;
            }
        } else {
             if (i < n / 2) {

             }
        }
    }
    bool fw = true;
    for (int i = 1; i < n - 1; i++) {
        if (s[i] == '1') {
            if (fw) {
                a[i] = '(';
                b[i] = '(';
            } else {
                a[i] = ')';
                b[i] = ')';
            }
            fw = !fw;
        }
    }
    printf("YES\n");
    for (int i = 0; i < n; i++) {
        printf("%c", a[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%c", b[i]);
    }
    printf("\n");
    /*     return; */
    /* } */
    /* printf("NO\n"); */
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
