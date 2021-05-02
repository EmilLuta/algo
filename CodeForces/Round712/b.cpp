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
    string a, b;
    cin >> a >> b;
    int ones = 0, zeros = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == '0') {
            zeros++;
        } else {
            ones++;
        }
    }
    int i = n - 1;
    bool flipped = false;
    while (i >= 0) {
        if ((a[i] != b[i] && !flipped) || (a[i] == b[i] && flipped)) {
            if (zeros == ones) {
                flipped = !flipped;
                swap(zeros, ones);
            } else {
                printf("NO\n");
                return;
            }
        }
        if (flipped) {
            if (a[i] == '1') {
                zeros--;
            } else {
                ones--;
            }
        } else {
            if (a[i] == '1') {
                ones--;
            } else {
                zeros--;
            }
        }
        i--;
    }
    printf("YES\n");
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
