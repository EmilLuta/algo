#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            if (i % 2 == 0) {
                x = abs(x);
            } else {
                x = -abs(x);
            }
            printf("%d ", x);
        }
        printf("\n");
    }
}
