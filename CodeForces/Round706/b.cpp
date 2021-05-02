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
    int n, k;
    scanf("%d%d", &n, &k);
    set<int> s;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        s.insert(x);
    }
    int current = -1;
    for (int i = 0; i <= n; i++) {
        if (s.count(i) == 0) {
            current = i;
            break;
        }
    }
    if (current == n) {
        printf("%d\n", n + k);
        return;
    }
    int maximum = 0;
    for (int x : s) {
        maximum = max(maximum, x);
    }
    for (int i = 0; i < k; i++) {
        int to_add = (current + maximum + 1) / 2;
        s.insert(to_add);
        if (to_add > current) {
            printf("%d\n", (int)s.size());
            return;
        }
        maximum = max(maximum, to_add);
        if (to_add == current) {
            for (int x = current; x <= 1e9; x++) {
                if(s.count(x) == 0) {
                    current = x;
                    break;
                }
            }
        }
    }
    printf("%d\n", (int)s.size());
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
