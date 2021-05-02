#include <bits/stdc++.h>

using namespace std;

// ios::sync_with_stdio(0);
// cin.tie(0);

# define deb_v(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << a[i] << " "; \
    cerr << ")\n";

# define deb(x) cerr << #x << " = " << x << "\n";

int get_sq(int a) {
    int i = 0;
    while (i * i <= a) {
        i++;
    }
    return i;
}

void solve(int t) {
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> ops;
    while (n > 2) {
        int sq = get_sq(n);
        for (int i = n - 1; i > sq; i--) {
            ops.push_back({i, n});
        }
        ops.push_back({n, sq});
        ops.push_back({n, sq});
        n = sq;
    }
    printf("%d\n", (int)ops.size());
    for (pair<int, int> x : ops) {
        printf("%d %d\n", x.first, x.second);
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
