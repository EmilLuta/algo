#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        int a, b, c, r;
        scanf("%d %d %d %d", &a, &b, &c, &r);
        if (a > b) {
            swap(a, b);
        }
        int left = c - r;
        int right = c + r;
        if (right <= a || left >= b) {
            printf("%d\n", b - a);
            continue;
        } else if (a <= left && b >= right) {
            printf("%d\n", left - a + b - right);
            continue;
        } else if (right <= b && a >= left) {
            printf("%d\n", b - right);
            continue;
        } else if (a <= left && b <= right) {
            printf("%d\n", left - a);
            continue;
        } else if (a >= left && b <= right) {
            printf("%d\n", 0);
            continue;
        }
        assert(false);
    }
}
