#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    int s = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        s += a[i];
    }
    if (s == 0) {
        printf("NO\n");
        return;
    }
    printf("YES\n");
    sort(a.begin(), a.end());
    if (s > 0) {
        reverse(a.begin(), a.end());
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
