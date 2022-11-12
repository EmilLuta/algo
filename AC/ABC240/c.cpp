#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x;
    scanf("%d%d", &n, &x);
    vector<int> a(n), b(n);
    set<int> values, now = {0};
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a[i], &b[i]);
        for (int val : now) {
            values.insert(val + a[i]);
            values.insert(val + b[i]);
        }
        now = values;
        values.clear();
    }
    if (now.count(x) != 0) {
        printf("Yes\n");
        return 0;
    }
    printf("No\n");
}
