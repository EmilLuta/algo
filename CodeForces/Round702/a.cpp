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

int get_log(int a) {
    int c = 0;
    while ((1 << c) < a) {
        c++;
    }
    return c - 1;
}

void solve(int t) {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int answer = 0;
    for (int i = 1; i < n; i++) {
        int s = min(a[i], a[i - 1]);
        int b = max(a[i], a[i - 1]);
        int c = 0;
        while (!((b / s < 2)  || (b / s == 2 && b % s == 0))) {
            c++;
            s *= 2;
        }
        answer += c;
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
