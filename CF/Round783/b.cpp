#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a.begin(), a.end());
    long long current_index = 1;
    for (int i = 1; i < n; i++) {
        current_index += a[i] + 1;
    }
    current_index += a[n - 1];
    if (current_index <= m) {
        printf("YES\n");
        return;
    }
    printf("NO\n");
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        solve();
    }
}
