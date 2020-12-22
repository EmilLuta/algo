#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a.begin(), a.end());
    long long answer = -243'000'000'000'000'000;
    for (int i = 0; i < 5; i++) {
        long long current = 1;
        for (int start = 0; start < i; start++) {
            current *= a[start];
        }
        for (int end = n - 1; end >= n - 5 + i; end--) {
            current *= a[end];
        }
        answer = max(answer, current);
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
