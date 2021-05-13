#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x;
    scanf("%d%d", &n, &x);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    vector<int> diff;
    int s = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != x) {
            diff.push_back(a[i]);
        }
        s += a[i] - x;
    }
    if (diff.size() == 0) {
        printf("0\n");
        return;
    }
    if ((s == 0) || (diff.size() < n)) {
        printf("1\n");
        return;
    }
    printf("2\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
