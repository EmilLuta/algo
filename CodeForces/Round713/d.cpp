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
    vector<int> a(n + 2);
    long long sum = 0;
    for (int i = 0; i < n + 2; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    sort(a.begin(), a.end());
    bool found = false;
    for (int i = 0; i < n + 2; i++) {
        if (i != n + 1 && sum - a[n + 1] - a[i] == a[n + 1]) {
            a[n + 1] = -1;
            a[i] = -1;
            found = true;
            break;
        }
        if (i != n && sum - a[n] - a[i] == a[n]) {
            a[n] = -1;
            a[i] = -1;
            found = true;
            break;
        }
    }
    if (found) {
        for (int i = 0; i < n + 2; i++) {
            if (a[i] == -1) {
                continue;
            }
            printf("%d ", a[i]);
        }
        printf("\n");
    } else {
        printf("-1\n");
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
