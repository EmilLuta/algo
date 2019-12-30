#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    vector<int> a(n), b(n), c(n);
    vector<pair<int, int>> portals(m);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &a[i], &b[i], &c[i]);
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        portals[i] = {x, y};
    }
}
