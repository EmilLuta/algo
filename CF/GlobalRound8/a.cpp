#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        int a, b, n;
        scanf("%d%d%d", &a, &b, &n);
        if (a > b) {
            swap(a, b);
        }
        bool now_a = true;
        int step = 0;
        while (a <= n && b <= n) {
            if (now_a) {
                a += b;
            } else {
                b += a;
            }
            now_a = !now_a;
            step++;
        }
        printf("%d\n", step);
    }
}
