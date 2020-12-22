#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        int n, m;
        scanf("%d%d", &n, &m);
        set<int> a;
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            a.insert(x);
        }
        int val = -1;
        for (int i = 0; i < m; i++) {
            int x;
            scanf("%d", &x);
            if (a.count(x) != 0) {
                val = x;
            }
        }
        if (val != -1) {
            printf("YES\n1 %d\n", val);
        } else {
            printf("NO\n");
        }
    }
}
