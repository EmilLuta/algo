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



void solve(int t, set<long long>& have) {
    long long x;
    scanf("%lld", &x);
    for (long long opt : have) {
        if (have.count(x - opt) != 0) {
            printf("YES\n");
            return;
        }
    }
    printf("NO\n");
}

int main() {
    set<long long> have;
    for (long long i = 1; i <= 10000; i++) {
        have.insert(i * i * i);
    }
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i, have);
    }
}
