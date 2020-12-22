/*
 * 4
8
1 2 0 7 2 0 2 0
6
4 8 15 16 23 42
9
3 1 4 1 5 9 2 6 5
6
9 9 9 9 9 9
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    for (int tc = 1; tc <= t; tc++) {
        int n;
        scanf("%d", &n);
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        int max_so_far = -1;
        int c = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > max_so_far) {
                max_so_far = a[i];
                if (i == n - 1) {
                    c++;
                    continue;
                }
                if (a[i] > a[i + 1]) {
                    c++;
                }
            }
        }
        printf("Case #%d: %d\n", tc, c);
    }
}
