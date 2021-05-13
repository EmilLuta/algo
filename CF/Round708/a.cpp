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
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int f = 0;
    int b = n - 1;
    sort(a.begin(), a.end());
    vector<int> out(n);
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            if (a[i] == a[i - 1]) {
                out[b] = a[i];
                b--;
            } else {
                out[f] = a[i];
                f++;
            }
        } else {
            out[f] = a[i];
            f++;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", out[i]);
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
