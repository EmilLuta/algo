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
    vector<int> a(n);
    /* map<int, vector<int>> m; */
    vector<vector<int>> m(n + 1);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        m[a[i]].push_back(i);
    }
    int index = -1;
    int max_so_far = 0;
    vector<int> out;
    while (index < n) {
        printf("index = %d\n", index);
        for (int val = 0; val <= n; val++) {
            auto v = m[val];
            auto ptr = lower_bound(v.begin(), v.end(), index);
            if (ptr == v.end()) {
                printf("-\n");
                out.push_back(val);
                max_so_far++;
                index = max_so_far;
                break;
            } else {
                max_so_far = max(max_so_far, *ptr);
                printf("%d\n", *ptr);

            }
        }
    }
    printf("index = %d\n", index);
    printf("%d\n", (int)out.size());
    for (int x : out) {
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
