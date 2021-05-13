#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            printf("%d ", i);
        }
        printf("\n");
        /* for (int i = 1; i <= n; i++) { */
        /*     int mor = 0; */
        /*     for (int j = i + 1; j <= n; j++) { */
        /*         mor |= j; */
        /*         if (j - i + 1 > mor) { */
        /*             printf("i = %d; j = %d; j - i + 1 = %d; mor = %d\n", i, j, j - i + 1, mor); */
        /*         } */
        /*     } */
        /* } */
    }
}
