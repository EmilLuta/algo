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
    int n, l, r, s;
    scanf("%d%d%d%d", &n, &l, &r, &s);
    int total_max = 0, total_min = 0;
    for (int i = n; i >= n - (r - l + 1); i--) {
        total_max += i;
    }
    for (int i = 1; i < r - l + 2; i++) {
        total_min += i;
    }
    if (total_max < s || total_min > s) {
        printf("-1\n");
        return;
    }
    int len = r - l + 1;
    vector<int> a(len);
    int s_now = 0;
    for (int i = 0; i < len; i++) {
        a[i] = i + 1;
        s_now += a[i];
    }
    if (s_now != s) {
        for (int i = len - 1; i >= 0; i--) {
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
