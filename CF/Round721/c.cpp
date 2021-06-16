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
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    map<int, int> c;
    int answer = 0;
    for (int i = 0; i < n; i++) {
        if (c.count(a[i]) != 0) {
            answer += (n - i) * c[a[i]];
            printf("%d at position %d will form %d pairs from behind\n", a[i], i, (n - i) * c[a[i]]);
        }
        c[a[i]]++;
    }
    c.clear();
    for (int i = n - 1; i > 0; i--) {
        if (c.count(a[i]) != 0) {
            answer += i * c[a[i]];
            printf("%d at position %d will form %d pairs from ahead\n", a[i], i, i * c[a[i]]);
        }
        c[a[i]]++;
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
