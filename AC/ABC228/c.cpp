#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        a[i] = {x + y + z, i};
    }
    sort(a.begin(), a.end());
    vector<bool> answer(n, false);
    for (int i = 0; i < n; i++) {
        auto p = lower_bound(a.begin(), a.end(), make_pair(a[i].first + 300, (int)1e9));
        int pos = a.end() - p;
        if (pos < k) {
            answer[a[i].second] = true;
        }
    }
    for (int i = 0; i < n; i++) {
        if (answer[i]) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
}
