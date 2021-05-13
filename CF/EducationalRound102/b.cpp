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

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

void solve(int t) {
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    int l = lcm(n, m);
    string answer = "";
    for (int i = 0; i < l; i++) {
        if (a[i % n] != b[i % m]) {
            cout << "-1\n";
            return;
        }
        answer += a[i % n];
    }
    cout << answer << '\n';
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
