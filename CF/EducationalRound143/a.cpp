#include <bits/stdc++.h>

using namespace std;

void solve(int t) {
    int n, m;
    scanf("%d%d", &n, &m);
    string a, b;
    cin >> a >> b;
    reverse(b.begin(), b.end());
    a += b;
    int same = 0;
    for (int i = 1; i < n + m; i++) {
        if (a[i] == a[i - 1]) {
            same++;
        }
    }
    if (same <= 1) {
        printf("YES\n");
        return;
    }
    printf("NO\n");
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        solve(t);
    }
}
