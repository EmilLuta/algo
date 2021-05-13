#include <bits/stdc++.h>

using namespace std;

// ios::sync_with_stdio(0);
// cin.tie(0);

# define deb_v(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << a[i] << " "; \
    cerr << ")\n";

# define deb(x) cerr << #x << " = " << x << "\n";

void solve(int t) {
    string a;
    cin >> a;
    int n = a.length();
    if (n % 2 == 1) {
        printf("NO\n");
        return;
    }
    int c = 0;
    int q = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == '(') {
            c++;
        } else if (a[i] == ')') {
            c--;
        } else {
            q++;
        }
        if (c < 0) {
            if (q == 0) {
                printf("NO\n");
                return;
            }
            q--;
        }
    }
    c = 0;
    q = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == '(') {
            c--;
        } else if (a[i] == ')') {
            c++;
        } else {
            q++;
        }
        if (c < 0) {
            if (q == 0) {
                printf("NO\n");
                return;
            }
            q--;
        }
    }
    printf("YES\n");
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
