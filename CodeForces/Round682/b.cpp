#include <bits/stdc++.h>

using namespace std;

# define deb_v(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << a[i] << " "; \
    cerr << ")\n";

# define deb(x) cerr << #x << " = " << x << "\n";

void solve(int t) {
    int n;
    scanf("%d", &n);
    vector<int> b(n);
    bool answer = false;
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        m[b[i]]++;
        if (m[b[i]] > 1) {
            answer = true;
        }
    }
    if (answer) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
