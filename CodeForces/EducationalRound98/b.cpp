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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a.begin(), a.end());
    int filler = (a[0] / (n - 1) + 1) * (n - 1);
    long long s = 0;
    for (int i = 1; i < n; i++) {
        s += a[i];
    }
    long long answer = 0;
    while (filler < INT_MAX - (n - 1)) {
        int target = (s + filler) / (n - 1);
        int take = filler;
        bool ok = true;
        for (int i = 1; i < n; i++) {
            if (target - a[i] < take) {
                filler += n - 1;
                ok = false;
                break;
            }
            answer += target - a[i];
            take -= target - a[i];
        }
        if (ok) {
            printf("%lld\n", answer);
            return;
        }
    }

}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
