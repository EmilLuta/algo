#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if (a == 0 && b == 0) {
        return 1;
    }
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

void solve() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int on_same_slope = 1;
    for (int i = 0; i < n; i++) {
        map<pair<int, int>, int> slopes;
        for (int j = i + 1; j < n; j++) {
            int y = j - i;
            int x = a[j] - a[i];
            int g = gcd(x, y);
            x /= g;
            y /= g;
            slopes[{y, x}] += 1;
        }
        for (pair<pair<int, int>, int> slope : slopes) {
            on_same_slope = max(on_same_slope, slope.second);
        }
    }
    printf("%d\n", max(0, n - on_same_slope - 1));
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
