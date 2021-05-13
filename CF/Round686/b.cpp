#include <bits/stdc++.h>

using namespace std;

// ios::sync_with_stdio(0);
// cin.tie(0);

# define deb_v(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << a[i] << " "; \
    cerr << ")\n";

# define deb(x) cerr << #x << " = " << x << "\n";

void solve(int t) {
    int n;
    scanf("%d", &n);
    map<int, vector<int>> m;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        m[x].push_back(i + 1);
    }
    for (pair<int, vector<int>> p : m) {
        if (p.second.size() == 1) {
            printf("%d\n", p.second[0]);
            return;
        }
    }
    printf("-1\n");
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
