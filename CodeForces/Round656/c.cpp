#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        int n;
        scanf("%d", &n);
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        bool increasing = true;
        int i = n - 1;
        for (i = n - 1; i >= 1; i--) {
            if (increasing) {
                if (a[i] > a[i - 1]) {
                    increasing = false;
                }
            } else {
                if (a[i] < a[i - 1]) {
                    break;
                }
            }
        }
        if (i == 1) {
            if (increasing || (!increasing && a[0] <= a[1])) {
                i--;
            }
        }
        printf("%d\n", i);
    }
}
