#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        int a, b;
        scanf("%d%d", &a, &b);
        }
        if (((a + b) % 3 != 0) || (2 * a < b || 2 * b < a)) {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
    }
}
