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
    vector<int> a(n), seen(n + 1, 0), answer;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int biggest_seen = n;
    seen[biggest_seen] = 1;
    int i = n - 1;
    int last = n;
    while (i >= 0) {
        if (a[i] == biggest_seen) {
            for (int j = i; j < last; j++) {
                answer.push_back(a[j]);
                seen[a[j]] = 1;
            }
            last = i;
            while (biggest_seen > 0 && seen[biggest_seen] == 1) {
                biggest_seen--;
            }
        }
        i--;
    }
    /* printf("answer.size() = %d\n", (int)answer.size()); */
    for (int x : answer) {
        printf("%d ", x);
    }
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
