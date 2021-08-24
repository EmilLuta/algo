#include <bits/stdc++.h>

using namespace std;

void solve(vector<int>& a, int i, int n, int m, int& c) {
    if (i == n) {
        for (int j = 0; j < n - 1; j++) {
            if (abs(a[j] - a[j + 1]) > 1) {
                return;
            }
        }
        c++;
        printf("a = [");
        for (int j = 0; j < n; j++) {
            printf("%d ", a[j]);
        }
        printf("]\n");
        return;
    }
    if (a[i] == 0) {
        for (int j = 1; j <= m; j++) {
            a[i] = j;
            solve(a, i + 1, n, m, c);
            a[i] = 0;
        }
    } else {
        solve(a, i + 1, n, m, c);
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int c = 0;
    solve(a, 0, n, m, c);
    printf("%d\n", c);
}
