#include <bits/stdc++.h>

using namespace std;

// ios::sync_with_stdio(0);
// cin.tie(0);

# define deb_v(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << a[i] << " "; \
    cerr << ")\n";

# define deb(x) cerr << #x << " = " << x << "\n";

void solve(int t) {
    int n, q;
    scanf("%d%d", &n, &q);
    string s;
    cin >> s;
    for (int x = 0; x < q; x++) {
        int l, r;
        scanf("%d%d", &l, &r);
        l--;
        r--;
        bool found = false;
        for (int i = 0; i < l; i++) {
            if (s[i] == s[l]) {
                found = true;
                break;
            }
        }
        for (int i = r + 1; i < n; i++) {
            if (s[i] == s[r]) {
                found = true;
                break;
            }
        }
        if (found) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
