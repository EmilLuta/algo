#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q, z = 0, o = 0;
    scanf("%d%d", &n, &q);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] == 0) {
            z++;
        } else {
            o++;
        }
    }
    for (int i = 0; i < q; i++) {
        int type, val;
        scanf("%d%d", &type, &val);
        if (type == 1) {
            a[val - 1] = 1 - a[val - 1];
            if (a[val - 1] == 0) {
                z++;
                o--;
            } else {
                z--;
                o++;
            }
        }
        if (type == 2) {
            if (val > o) {
                printf("0\n");
            } else {
                printf("1\n");
            }
        }
    }
}
