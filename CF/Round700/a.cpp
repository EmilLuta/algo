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
    bool is_alice = true;
    for (int i = 0; i < n; i++) {
        if (is_alice) {
            if (s[i] == 'a') {
                s[i] = 'b';
            } else {
                s[i] = 'a';
            }
        } else {
            if (s[i] == 'z') {
                s[i] = 'y';
            } else {
                s[i] = 'z';
            }
        }
        is_alice = !is_alice;
    }
    cout << s << endl;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
