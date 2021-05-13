#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    bool go_w = true;
    long long w = 0, b = 0;
    for (int i = 0; i < n; i++) {
        if (go_w) {
            w += (a[i] + 1) / 2;
            b += a[i] / 2;
        } else {
            w += a[i] / 2;
            b += (a[i] + 1) / 2;
        }
        go_w = !go_w;
    }
    printf("%lld\n", min(w, b));
}
