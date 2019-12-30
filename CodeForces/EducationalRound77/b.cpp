#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (a < b) {
            swap(a, b);
        }
        int x = a - b;
        if (x > b) {
            printf("NO\n");
            continue;
        }
        a -= 2 * x;
        if (a % 3 == 0) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
}
