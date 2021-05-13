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

int pow_4(int a) {
    return a * a * a * a;
}

int main() {
    int mul = 720720;
    int n, m;
    scanf("%d%d", &n, &m);
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            int x;
            scanf("%d", &x);
            if ((r + c) % 2 == 0) {
                printf("%d ", mul);
            } else {
                printf("%d ", mul + pow_4(x));
            }
        }
        printf("\n");
    }
}
