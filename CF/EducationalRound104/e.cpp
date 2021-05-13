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

const int MAX = 400000001;

int main() {
    vector<int> n(4);
    for (int i = 0; i < 4; i++) {
        scanf("%d", &n[i]);
    }
    vector<vector<pair<int, int>>> a(4);
    for (int i = 0; i < 4; i++) {
        a[i].resize(n[i]);
        for (int j = 0; j < n[i]; j++) {
            scanf("%d", &a[i][j].first);
            a[i][j].second = j + 1;
        }
    }
    vector<int> m(3);
    for (int i = 0; i < 3; i++) {
        scanf("%d", &m[i]);
        set<pair<int, int>> invalid;
        for (int j = 0; j < m[i]; j++) {
            int w, z;
            scanf("%d%d", &w, &z);
            invalid.insert({w, z});
        }
        sort(a[i].begin(), a[i].end());
        for (int j = 0; j < n[i + 1]; j++) {
            bool found = false;
            for (int k = 0; k < n[i]; k++) {
                if (invalid.count({a[i][k].second, a[i + 1][j].second}) == 0) {
                    a[i + 1][j].first += a[i][k].first;
                    found = true;
                    break;
                }
            }
            if (!found) {
                a[i + 1][j].first = MAX;
            }
        }
        /* printf("x = {"); */
        /* for (int j  = 0; j < n[i + 1]; j++) { */
        /*     printf("(%d %d) ", a[i + 1][j].first, a[i + 1][j].second); */
        /* } */
        /* printf("}\n"); */
    }
    int answer = INT_MAX;
    for (int i = 0; i < n[3]; i++) {
        answer = min(answer, a[3][i].first);
    }
    if (answer >= MAX) {
        printf("-1\n");
    } else {
        printf("%d\n", answer);
    }
}
