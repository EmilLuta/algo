#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    for (int i = 0; i < n; i++) {
        int curr = sum - a[i];
        if (curr % (n - 1) == 0 && curr / (n - 1) == a[i]) {
            printf("Yes\n");
            return;
        }
    }
    printf("No\n");

}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
