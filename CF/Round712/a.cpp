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
    bool only_a = true;
    int index = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != 'a') {
            only_a = false;
            index = i;
            break;
        }
    }
    if (only_a) {
        printf("NO\n");
        return;
    }
    if (index < n / 2) {
        s.insert(n - index, "a");
    } else {
        s.insert(index - n / 2, "a");
    }
    cout << "YES\n" << s << endl;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
