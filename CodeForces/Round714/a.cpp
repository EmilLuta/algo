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
    vector<int> a(n, 0);
    int curr = n, peaks = k;
    for (int i = 1; i < n - 1 && peaks != 0; i += 2) {
        a[i] = curr;
        curr--;
        peaks--;
    }
    if (peaks > 0) {
        printf("-1\n");
        return;
    }
    int val = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            a[i] = val;
            val++;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
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
