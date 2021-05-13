#include <bits/stdc++.h>

using namespace std;

// ios::sync_with_stdio(0);
// cin.tie(0);

# define deb_v(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << a[i] << " "; \
    cerr << ")\n";

# define deb(x) cerr << #x << " = " << x << "\n";

void solve(int t) {
    long long n;
    scanf("%lld", &n);
    long long x = n;
    long long i = 2;
    map<long long, int> m;
    while (i * i <= n) {
        if (n % i == 0) {
            n /= i;
            m[i]++;
            continue;
        }
        i++;
    }
    if (n != 1) {
        m[n]++;
    }
    if (m.size() == 0) {
        printf("1\n%lld\n", n);
        return;
    }
    int maximum = 0;
    long long val = 0;
    for (pair<long long, int> p : m) {
        if (p.second > maximum) {
            maximum = p.second;
            val = p.first;
        }
    }
    printf("%d\n", maximum);
    while (maximum > 1) {
        printf("%lld ", val);
        maximum--;
        x /= val;
    }
    printf("%lld\n", x);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
