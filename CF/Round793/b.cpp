#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int all_and = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] != i) {
            if (all_and == -1) {
                all_and = i;
            } else {
                all_and &= i;
            }
        }
    }
    printf("%d\n", all_and);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
