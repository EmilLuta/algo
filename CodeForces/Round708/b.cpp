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
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> counter(m, 0);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        counter[x % m]++;
    }
    int groups = 0;
    if (counter[0] > 0) {
        groups++;
        counter[0] = 0;
    }
    for (int i = 1; i < m; i++) {
        int a = i;
        int b = m - i;
        if (counter[a] > 0) {
            if (a == b) {
                groups++;
                counter[i] = 0;
                continue;
            }
            if (counter[b] > 0) {
                int minimum = min(counter[a], counter[b]);
                counter[a] -= minimum;
                counter[b] -= minimum;
                groups++;
                if (counter[a] > 0) {
                    counter[a]--;
                } else if (counter[b] > 0) {
                    counter[b]--;
                }
                groups += max(0, counter[a]);
                groups += max(0, counter[b]);
                counter[a] = 0;
                counter[b] = 0;
            } else {
                groups += counter[a];
            }
        }
    }
    printf("%d\n", groups);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
