#include <bits/stdc++.h>

using namespace std;

int main() {
    int q;
    scanf("%d", &q);
    map<int, int> m;
    for (int i = 0; i < q; i++) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int val;
            scanf("%d", &val);
            m[val]++;
        } else if (t == 2) {
            int val;
            int times;
            scanf("%d%d", &val, &times);
            m[val] -= times;
            if (m[val] <= 0) {
                m.erase(val);
            }
        } else if (t == 3) {
            printf("%d\n", m.rbegin()->first - m.begin()->first);
        } else {
            return -4;
        }
    }
}
