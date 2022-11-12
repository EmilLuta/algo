#include <bits/stdc++.h>

using namespace std;

int to_make_1(int n) {
    int steps = 0;
    while (n % 2 == 0) {
        n = n / 2;
        steps++;
    }
    return steps;
}

void solve() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    int odds = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] % 2 == 1) {
            odds++;
        }
    }
    if (odds != 0) {
        printf("%d\n", n - odds);
        return;
    }
    int min_make_one = 1e9;
    for (int i = 0; i < n; i++) {
        min_make_one = min(min_make_one, to_make_1(a[i]));
    }
    printf("%d\n", n - 1 + min_make_one);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
