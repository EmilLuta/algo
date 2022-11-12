#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> a(n);
    set<int> ind_max;
    int max = -1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] > max) {
            ind_max.clear();
            max = a[i];
        }
        if (a[i] == max) {
            ind_max.insert(i + 1);
        }
    }
    for (int i = 0; i < k; i++) {
        int x;
        scanf("%d", &x);
        if (ind_max.count(x) != 0) {
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
}
