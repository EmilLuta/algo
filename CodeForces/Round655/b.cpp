#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        int n;
        scanf("%d", &n);
        int a = INT_MAX;
        int b = INT_MAX;
        int l = INT_MAX;
        int i = 2;
        while (i * i <= n) {
            if (n % i == 0) {
                int d = n / i;
                for (int j = 1; j < (i + 1) / 2; j++) {
                    int x = d * (i - j);
                    int y = d * j;
                    if (x % y == 0 && x < a) {
                        a = x;
                        b = y;
                    }
                }
            }
            i++;
        }
        if (a == INT_MAX) {
            a = n - 1;
            b = 1;
        }
        printf("%d %d\n", a, b);
    }
}
