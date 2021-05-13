#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        int n;
        scanf("%d", &n);
        vector<int> perm(n);
        vector<int> pos(n + 1);
        int one_index;
        for (int i = 0; i < n; i++) {
            scanf("%d", &perm[i]);
            pos[perm[i]] = i;
        }
        int maximum = pos[1];
        int minimum = pos[1];
        printf("1");
        for (int i = 2; i <= n; i++) {
            maximum = max(maximum, pos[i]);
            minimum = min(minimum, pos[i]);
            if (maximum - minimum == i - 1) {
                printf("1");
            } else {
                printf("0");
            }
        }
        printf("\n");
    }
}
