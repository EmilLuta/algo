#include <bits/stdc++.h>

using namespace std;

# define deb_v(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << a[i] << " "; \
    cerr << ")\n";

# define deb(x) cerr << #x << " = " << x << "\n";

void solve(int t) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int c = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == ')') {
            c++;
        } else {
            break;
        }
    }
    if (c > n / 2) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
