#include <bits/stdc++.h>

using namespace std;

// ios::sync_with_stdio(0);
// cin.tie(0);

# define deb_v(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << a[i] << " "; \
    cerr << ")\n";

# define deb(x) cerr << #x << " = " << x << "\n";


void solve(int t) {
    int n, k;
    cin >> n >> k;
    string a, b;
    cin >> a >> b;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int i = 0;
    while (i < n) {
        while (i < n && a[i] == b[i]) {
            i++;
        }
        if (i == n) {
            cout << "Yes\n";
            return;
        }
        if (i + k - 1 >= n || a[i] != a[i + k - 1] || a[i] > b[i]) {
            cout << "No\n";
            return;
        }
        i += k;
    }
    cout << "Yes\n";
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
