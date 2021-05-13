#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        int n, k;
        scanf("%d %d", &n, &k);
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        int c = 0, so_far = 1;
        for (int i = 0; i < n; i++) {
            if (so_far * a[i] >= k) {
                c++;
                so_far = 1;
            } else {
                so_far++;
            }
        }
        printf("%d\n", c);
    }
}
