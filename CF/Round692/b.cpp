#include <bits/stdc++.h>

using namespace std;

# define deb_v(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << item << " "; \
    cerr << ")\n";

# define deb(x) cerr << #x << " = " << x << "\n";

void solve(int t) {
    long long n;
    scanf("%lld", &n);
    long long x = n;
    vector<int> d(10, 0);
    while (n != 0) {
        d[n % 10]++;
        n /= 10;
    }
    bool found = false;
    while (!found) {
        found = true;
        for (int i = 1; i <= 9; i++) {
            if (d[i] > 0) {
                if (x % i != 0) {
                    found = false;
                }
            }
        }
        if (found) {
            printf("%lld\n", x);
            return;
        }
        n = x;
        while (n % 10 == 9) {
            d[9]--;
            n /= 10;
        }
        d[n % 10]--;
        d[(n % 10) + 1]++;
        x++;
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
