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
    int answer = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == -1) {
            continue;
        }
        int c = 0;
        int j = i;
        int k = j;
        while (j < n && a[j] != -1) {
            k = j;
            c += a[j];
            j += a[j];
            a[k] = -1;
        }
        answer = max(answer, c);
    }
    printf("%d\n", answer);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
