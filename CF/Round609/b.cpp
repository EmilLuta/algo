#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> a(n), b(n), c(n), diffs(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    sort(b.begin(), b.end());
    int min_x = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (b[0] >= a[i]) {
            diffs[i] = (b[0] - a[i]) % m;
        } else {
            diffs[i] = m - a[i] + b[0];
        }
    }
    for (int i = 0; i < n; i++) {
        int x = diffs[i];
        for (int j = 0; j < n; j++) {
            c[j] = (a[j] + x) % m;
        }
        sort(c.begin(), c.end());
        bool found = true;
        for (int j = 0; j < n; j++) {
            if (b[j] != c[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            min_x = min(min_x, x);
        }
    }
    printf("%d\n", min_x);
}
