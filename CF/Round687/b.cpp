#include <bits/stdc++.h>

using namespace std;

// ios::sync_with_stdio(0);
// cin.tie(0);

# define deb_v(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << a[i] << " "; \
    cerr << ")\n";

# define deb(x) cerr << #x << " = " << x << "\n";

void solve(int t) {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> a(n);
    vector<bool> colors(101, false);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        colors[a[i]] = true;
    }
    int answer = INT_MAX;
    for (int i = 1; i <= 100; i++) {
        if (colors[i]) {
            int current = 0;
            int j = 0;
            while (j < n) {
                if (a[j] != i) {
                    for (int x = 0; x < k; x++) {
                        j++;
                    }
                    current++;
                } else {
                    j++;
                }
            }
            answer = min(answer, current);
        }
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
