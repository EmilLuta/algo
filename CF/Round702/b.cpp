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
    int c0 = 0, c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        switch (x % 3) {
            case 0:
                c0++;
                break;
            case 1:
                c1++;
                break;
            case 2:
                c2++;
                break;
        }
    }
    int each = (c0 + c1 + c2) / 3;
    int answer = 0;
    while (c0 != each || c1 != each || c2 != each) {
        if (c0 > each) {
            c1++;
            c0--;
        } else if (c1 > each) {
            c2++;
            c1--;
        } else if (c2 > each) {
            c0++;
            c2--;
        }
        answer++;
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
