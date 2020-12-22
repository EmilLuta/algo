#include <bits/stdc++.h>

using namespace std;

# define deb_v(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << a[i] << " "; \
    cerr << ")\n";

# define deb(x) cerr << #x << " = " << x << "\n";

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    int m = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        m = max(m, a[i]);
    }
    int best = 0;
    int val = 0;
    for (int i = 2; i <= m; i++) {
        int curr = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] % i == 0) {
                curr++;
            }
        }
        if (curr > best) {
            best = curr;
            val = i;
        }
    }
    printf("%d\n", val);
}
