#include <bits/stdc++.h>

using namespace std;


# define deb_v(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << a[i] << " "; \
    cerr << ")\n";

# define deb(x) cerr << #x << " = " << x << "\n";

void solve(int t) {
    int n, c0, c1, h;
    scanf("%d%d%d%d", &n, &c0, &c1, &h);
    string s;
    cin >> s;
    int cost = 0;
    if (h + c1 < c0) {
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                cost += c1;
            } else {
                cost += c1 + h;
            }
        }
        printf("%d\n", cost);
        return;
    }
    if (h + c0 < c1) {
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                cost += c0;
            } else {
                cost += c0 + h;
            }
        }
        printf("%d\n", cost);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            cost += c1;
        } else {
            cost += c0;
        }
    }
    printf("%d\n", cost);

}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
