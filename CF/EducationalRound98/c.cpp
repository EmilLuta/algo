#include <bits/stdc++.h>

using namespace std;

// ios::sync_with_stdio(0);
// cin.tie(0);

# define deb_v(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << a[i] << " "; \
    cerr << ")\n";

# define deb(x) cerr << #x << " = " << x << "\n";

void solve(int t) {
    string s;
    cin >> s;
    int n = s.length();
    int p = 0, b = 0, answer = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            p++;
        } else if (s[i] == ')') {
            if (p > 0) {
                answer++;
                p--;
            }
        } else if (s[i] == '[') {
            b++;
        } else {
            if (b > 0) {
                answer++;
                b--;
            }
        }
    }
    printf("%d\n", answer);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
