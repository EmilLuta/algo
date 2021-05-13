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

int main() {
    int n, q, k;
    scanf("%d%d%d", &n, &q, &k);
    vector<int> a(n + 2, 0);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i + 1]);
    }
    a.push_back(k);
    for (int i = 0; i < q; i++) {
        int s, e;
        scanf("%d%d", &s, &e);
        int answer = a[s] - 1 + k - a[e] + 2 * (a[e] - a[s] - 1 + (s - e) + 1);
        printf("%d\n", answer);
    }
}
