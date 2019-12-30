#include <stdio.h>
#include <stdlib.h>

int main() {
    int t, n, k, answer, c[100005], d[100005];
    scanf("%d", &t);
    for (int test_case = 0; test_case < t; test_case++) {
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; i++) {
            scanf("%d", &c[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &d[i]);
        }
        answer = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int c_max = 0, d_max = 0;
                for (int k = i; k <= j; k++) {
                    if (c_max < c[k]) {
                        c_max = c[k];
                    }
                    if (d_max < d[k]) {
                        d_max = d[k];
                    }
                }
                if (abs(d_max - c_max) <= k) {
                    answer += 1;
                }
            }
        }
        printf("Case #%d: %d\n", test_case + 1, answer);
    }
    return 0;
}
