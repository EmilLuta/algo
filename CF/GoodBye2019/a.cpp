#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        int n, k1, k2;
        scanf("%d%d%d", &n, &k1, &k2);
        int m1 = 0, m2 = 0;
        for (int i = 0; i < k1; i++) {
            int item;
            scanf("%d", &item);
            m1 = max(m1, item);
        }
        for (int i = 0; i < k2; i++) {
            int item;
            scanf("%d", &item);
            m2 = max(m2, item);
        }
        if (m1 > m2) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
}
