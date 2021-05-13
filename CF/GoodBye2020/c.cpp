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
    int answer = 0;
    for (int i = 1; i < n; i++) {
        if (a[i - 1] == a[i] && a[i] != '?') {
            a[i] = '?';
            answer++;
        }
        if (i < n - 1 && a[i - 1] == a[i + 1] && a[i - 1] != '?') {
            a[i + 1] = '?';
            answer++;
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
