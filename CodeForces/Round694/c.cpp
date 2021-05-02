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
    vector<int> k(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &k[i]);
    }
    sort(k.begin(), k.end());
    reverse(k.begin(), k.end());
    vector<int> c(m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &c[i]);
    }
    int j = 0;
    long long answer = 0;
    for (int i = 0; i < n; i++) {
        int index = k[i] - 1;
        if (j < m && c[index] > c[j]) {
            answer += c[j];
            j++;
        } else {
            answer += c[index];
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
