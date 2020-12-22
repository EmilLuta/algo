#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k, l;
    scanf("%d%d%d", &n, &k, &l);
    vector<int> d(n);
    /* int maximum = 0; */
    for (int i = 0; i < n; i++) {
        scanf("%d", &d[i]);
        /* maximum = max(maximum, d[i]); */
    }
    for (int i = 0; i < n; i++) {
        if (a[i] > l) {
            printf("NO\n");
            return;
        }
        if (a[i] + k <= l) {
            continue;
        }
        int start = 0;
        while (i < n && a[i] + k > l) {
            i++;
        }
        int end = i - 1;
        if (end - start > 2 * k) {
            printf("NO\n");
            continue;
        }
    }
    if (k + maximum <= l) {
        printf("YES\n");
        continue;
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
