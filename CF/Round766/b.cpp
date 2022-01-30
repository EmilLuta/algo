#include <bits/stdc++.h>

using namespace std;

# define deb_v(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << item << " "; \
    cerr << ")\n";

# define deb(x) cerr << #x << " = " << x << "\n";

# define deb_v_p(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << "(" << item.first << ", " << item.second << ") "; \
    cerr << ")\n";

bool valid(int n_r, int n_c, int n, int m) {
    return 0 <= n_r && n_r < n && 0 <= n_c && n_c < m;
}

void solve(int t) {
    int n, m;
    scanf("%d%d", &n, &m);
    set<pair<int, int>> q;
    set<pair<int, int>> seen;
    vector<int> out;
    int start = 0;
    int val = 0;
    int nh = n / 2;
    int mh = m / 2;
    val = nh + mh;
    if (n % 2 == 0 && m % 2 == 0) {
        for (int i = nh - 1; i <= nh; i++) {
            for (int j = mh - 1; j <= mh; j++) {
                q.insert({i, j});
                seen.insert({i, j});
            }
        }
    }
    if (n % 2 == 1 && m % 2 == 1) {
        seen.insert({nh, mh});
        q.insert({nh, mh});
    }
    if (n % 2 + m % 2 == 1) {
        if (n % 2 == 1) {
            for (int i = mh - 1; i <= mh; i++) {
                q.insert({nh, i});
                seen.insert({nh, i});
            }
        }
        if (m % 2 == 1) {
            for (int i = nh - 1; i <= nh; i++) {
                q.insert({i, mh});
                seen.insert({i, mh});
            }
        }
    }
    set<pair<int, int>> n_q;
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    while (start < n * m) {
        if ((int)q.size() == 0) {
            q = n_q;
            n_q.clear();
            val++;
        }
        pair<int, int> curr = *q.begin();
        q.erase(curr);
        start++;
        out.push_back(val);
        for (pair<int, int> d : dirs) {
            int n_r = curr.first + d.first;
            int n_c = curr.second + d.second;
            if (valid(n_r, n_c, n, m) && seen.count({n_r, n_c}) == 0) {
                n_q.insert({n_r, n_c});
                seen.insert({n_r, n_c});
            }
        }
    }
    for (int x : out) {
        printf("%d ", x);
    }
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
