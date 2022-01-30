#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (a - b == b - c) {
        printf("YES\n");
        return;
    }
    {
        /* fix a; */
        int target_a = b - (c - b);
        if (target_a > a && target_a % a == 0) {
            printf("YES\n");
            return;
        }
    }
    {
        /* fix b; */
        if ((c - a) % 2 == 0) {
            int target_b = (c - a) / 2 + a;
            if (target_b > b && target_b % b == 0) {
                printf("YES\n");
                return;
            }
        }
    }
    {
        /* fix c; */
        int target_c = (b - a) + b;
        if (target_c > c && target_c %c == 0) {
            printf("YES\n");
            return;
        }
    }
    printf("NO\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
