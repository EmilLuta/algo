#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    set<int> a;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if (a.count(x) == 0) {
            a.insert(x);
        } else {
            a.insert(-x);
        }
    }
    printf("%d\n", (int)a.size());
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
