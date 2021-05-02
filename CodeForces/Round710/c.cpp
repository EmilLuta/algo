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
    string a, b;
    cin >> a >> b;
    int n_a = a.size(), n_b = b.size();
    int n = min(n_a, n_b);
    for (int size = n; size >= 1; size--) {
        for (int i = 0; i <= n_a - size; i++) {
            for (int j = 0; j <= n_b - size; j++) {
                bool ok = true;
                for (int x = 0; x < size; x++) {
                    if (a[i + x] != b[j + x]) {
                        ok = false;
                    }
                }
                if (ok) {
                    /* cout << "a = "; */
                    /* for (int x = 0; x < size; x++) { */
                    /*     cout << a[i + x]; */
                    /* } */
                    /* cout << endl; */
                    /* cout << "b = "; */
                    /* for (int x = 0; x < size; x++) { */
                    /*     cout << b[j + x]; */
                    /* } */
                    /* cout << endl; */
                    printf("%d\n", n_a - size + n_b - size);
                    return;
                }
            }
        }
    }
    printf("%d\n", n_a + n_b);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
