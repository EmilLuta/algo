#include <bits/stdc++.h>

using namespace std;

void solve(int t) {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int x = a[0];
    int y = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) {
            y = a[i] - x;
        } else {
            x = a[i] - y;
            if (x < 0) {
                printf("NO\n");
                return;
            }
        }
    }
    printf("YES\n");
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
