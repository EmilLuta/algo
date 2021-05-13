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
    string s;
    cin >> s;
    int n = s.size();
    bool double_ones = false;
    for (int i = 1; i < n; i++) {
        if (s[i - 1] == s[i] && s[i] == '1') {
            double_ones = true;
        }
        if (double_ones && s[i - 1] == s[i] && s[i] == '0') {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
