#include <bits/stdc++.h>

using namespace std;

// ios::sync_with_stdio(0);
// cin.tie(0);

# define deb_v(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << a[i] << " "; \
    cerr << ")\n";

# define deb(x) cerr << #x << " = " << x << "\n";

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    long long x = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        x ^= a[i];
    }
    if (x == 0) {
        printf("-1\n");
    }
}
