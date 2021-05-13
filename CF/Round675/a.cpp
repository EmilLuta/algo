#include <bits/stdc++.h>

using namespace std;

void solve() {
    vector<int> a(3);
    scanf("%d%d%d", &a[0], &a[1], &a[2]);
    sort(a.begin(), a.end());
    if (a[0] + a[1] > a[2]) {
        printf("%d\n", a[0]);
    } else {
        printf("%d\n", a[2] - (a[0] + a[1]) + 1);
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
