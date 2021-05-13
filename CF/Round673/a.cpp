#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> a(n);
    int m = INT_MAX;
    int index = -1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] < m) {
            m = a[i];
            index = i;
        }
    }
    int answer = 0;
    for (int i = 0; i < n; i++) {
        if (i == index) {
            continue;
        }
        answer += (k - a[i]) / m;
    }
    printf("%d\n", answer);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
