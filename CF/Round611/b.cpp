#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        int n, k;
        scanf("%d%d", &n, &k);
        int a = n / k;
        int x = a * k;
        if (n - x >= k / 2) {
            printf("%d\n", a * k + k / 2);
        } else {
            printf("%d\n", n - x + a * k);
        }
    }
}
