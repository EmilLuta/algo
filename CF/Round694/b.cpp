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
    int n, x;
    scanf("%d%d", &n, &x);
    long long answer = 0;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        int w;
        scanf("%d", &w);
        a[i] = {w, 1};
    }
    int i = 0;
    bool stop = false;
    while (i < (int)a.size()) {
        answer += a[i].first * a[i].second;
        int q = a[i].first;
        int cnt = a[i].second;
        i++;
        if (stop) {
            continue;
        }
        if (q % x == 0) {
            int c = q / x;
            a.push_back({c, cnt * x});
        } else {
            stop = true;
        }
    }
    printf("%lld\n", answer);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
