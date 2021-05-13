#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }
    printf("2\n");
    int current = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        printf("%d %d\n", a[i], current);
        current = (a[i] + current + 1) / 2;
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
