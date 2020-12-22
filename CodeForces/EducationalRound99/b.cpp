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
    int answer = 0;
    int current = 0;
    for (int i = 1; current < n; i++) {
        current += i;
        answer++;
    }
    if (n == current || current - n >= 2) {
        printf("%d\n", answer);
    } else {
        printf("%d\n", answer + 1);
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
