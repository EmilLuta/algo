#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        m[x]++;
    }
    int a = -1, b = -1;
    for (int i = 0; i < n + 1; i++) {
        if (m[i] >= 2) {
            continue;
        }
        if (m[i] == 0) {
            if (a == -1) {
                printf("%d\n", i + i);
            } else {
                printf("%d\n", a + i);
            }
            return;
        }
        if (m[i] == 1) {
            if (a == -1) {
                a = i;
            }
        }
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
