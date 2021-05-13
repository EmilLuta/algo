#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    long long answer = 0;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
        answer = min(answer, sum);
    }
    printf("%lld\n", abs(answer));
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
