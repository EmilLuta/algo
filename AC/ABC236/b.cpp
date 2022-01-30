#include <bits/stdc++.h>

using namespace std;

# define deb_v(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << item << " "; \
    cerr << ")\n";

# define deb(x) cerr << #x << " = " << x << "\n";

# define deb_v_p(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << "(" << item.first << ", " << item.second << ") "; \
    cerr << ")\n";

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n + 1, 0);
    for (int i = 0; i < 4 * n - 1; i++) {
        int x;
        scanf("%d", &x);
        a[x]++;
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] != 4) {
            printf("%d\n", i);
            return 0;
        }
    }
}
