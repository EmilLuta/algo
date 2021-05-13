#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        int n;
        scanf("%d", &n);
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        sort(a.begin(), a.end());
        bool found = false;
        for (int i = 1; i <= 1024; i++) {
            vector<int> b(n);
            for (int j = 0; j < n; j++) {
                b[j] = a[j] ^ i;
            }
            sort(b.begin(), b.end());
            vector<int> v(n * 2);
            vector<int>::iterator it;
            it = set_intersection(a.begin(), a.end(), b.begin(), b.end(), v.begin());
            v.resize(it-v.begin());
            /* if (i == 1) { */
            /*     printf("v.size = %d\n", v.size()); */
            /*     for (int i = 0; i < v.size(); i++) { */
            /*         printf("%d ", v[i]); */
            /*     } */
            /*     printf("\n"); */
            /*     printf("a = ["); */
            /*     for (int x = 0; x < n; x++) { */
            /*         printf("%d ", a[x]); */
            /*     } */
            /*     printf("]\n"); */
            /*     printf("b = ["); */
            /*     for (int x = 0; x < n; x++) { */
            /*         printf("%d ", b[x]); */
            /*     } */
            /*     printf("]\n"); */
            /*     printf("v = ["); */
            /*     for (int x = 0; x < v.size(); x++) { */
            /*         printf("%d ", v[x]); */
            /*     } */
            /*     printf("]\n"); */
            /* } */
            if (v.size() == n) {
                found = true;
                printf("%d\n", i);
                break;
            }
        }
        if (!found) {
            printf("-1\n");
        }
    }
}
