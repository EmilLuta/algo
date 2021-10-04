#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    vector<int> dp;
    for (int x : a) {
        auto it = lower_bound(dp.begin(), dp.end(), x);
        if (it == dp.end()) {
            dp.push_back(x);
            continue;
        }
        *it = x;
    }
    printf("%d\n", (int)dp.size());
}
