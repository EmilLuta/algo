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
    int ones = 0;
    int twos = 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if (x == 1) {
            ones++;
        } else {
            twos++;
        }
    }
    if ((ones & 1) == 1 || (ones == 0 && ((twos & 1) == 1)) || ((twos * 2 + ones) & 1) == 1) {
        printf("NO\n");
        return;
    }
    printf("YES\n");
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
