#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    vector<int> a(n), b(n);
    int min_a = INT_MAX, min_b = INT_MAX;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        min_a = min(min_a, a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        min_b = min(min_b, b[i]);
    }
    long long answer = 0;
    for (int i = 0; i < n; i++) {
        long long from_a = a[i] - min_a;
        long long from_b = b[i] - min_b;
        answer += min(from_a, from_b) + abs(from_a - from_b);
    }
    printf("%lld\n", answer);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
