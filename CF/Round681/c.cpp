#include <bits/stdc++.h>

using namespace std;

struct order {
    int c;
    int p;
    int d;
};

void solve() {
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> a(n);
    vector<order> c(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].first);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].second);
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    int cost = 0;
    for (int i = 0; i < n; i++) {
        cost = min(cost + a[i].second, max(cost, a[i].first));
    }
    printf("%d\n", cost);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
