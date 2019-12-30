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
        bool found = false;
        for (int i = 1; i < n; i++) {
            if (abs(a[i] - a[i - 1]) >= 2) {
                printf("YES\n");
                printf("%d %d\n", i, i + 1);
                found = true;
                break;
            }
        }
        if (!found) {
            printf("NO\n");
        }
    }
}
