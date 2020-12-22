#include <bits/stdc++.h>

using namespace std;



int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        int l, r;
        scanf("%d%d", &l, &r);
        if (r / 2 < l) {
            printf("-1 -1\n");
        } else {
            printf("%d %d\n", l, l * 2);
        }
    }
}
