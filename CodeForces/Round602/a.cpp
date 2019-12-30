#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        int n;
        scanf("%d", &n);
        int max_l = INT_MIN;
        int min_r = INT_MAX;
        for (int i = 0; i < n; i++) {
            int l, r;
            scanf("%d %d", &l, &r);
            max_l = max(max_l, l);
            min_r = min(min_r, r);
        }
        printf("%d\n", max(0, max_l - min_r));
    }
}
