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
        long long s = 0;
        bool no = false;
        for (int i = 0; i < n; i++) {
            s += a[i];
            if (s <= 0) {
                no = true;
                break;
            }
        }
        if (no) {
            printf("NO\n");
            continue;
        }
        s = 0;
        no = false;
        for (int i = n - 1; i >= 0; i--) {
            s += a[i];
            if (s <= 0) {
                no = true;
                break;
            }
        }
        if (no) {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
    }
}
