#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int n, m, odd_l = 0, odd_r = 0, even_l = 0, even_r, current;
        scanf("%d", &n);
        for (int j = 0; j < n; j++) {
            scanf("%d", &current);
            if (current % 2 == 0) {
                even_r++;
            } else {
                odd_r++;
            }
        }
        scanf("%d", &m);
        for (int j = 0; j < m; j++) {
            scanf("%d", &current);
            if (current % 2 == 0) {
                even_l++;
            } else {
                odd_l++;
            }
        }
        printf("%d\n", odd_l * odd_r + even_l * even_r);
    }
}
