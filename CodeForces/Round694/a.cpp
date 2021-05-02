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
    long long minimum = 0, maximum = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        maximum += x / k;
        if (x % k != 0) {
            maximum++;
        }
        sum += x;
    }
    minimum = sum / k;
    if (sum % k != 0) {
        minimum++;
    }
    printf("%lld %lld\n", minimum, maximum);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
