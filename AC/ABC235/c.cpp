#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    map<int, vector<int>> m;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        m[x].push_back(i);
    }
    for (int i = 0; i < q; i++) {
        int x, k;
        scanf("%d%d", &x, &k);
        if (m.count(x) != 0) {
            if ((int)m[x].size() >= k) {
                printf("%d\n", m[x][k - 1] + 1);
                continue;
            }
        }
        printf("-1\n");
    }
}
