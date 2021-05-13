#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        int n, m;
        scanf("%d%d", &n, &m);
        vector<int> a(n);
        vector<int> b(n);
        map<int, int> rev;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < m; i++) {
            scanf("%d", &b[i]);
        }
        for (int i = 0; i < n; i++) {
            rev[a[i]] = i;
        }
        set<int> to_shuffle;
        long long c = 0;
        int last_index = 0;
        for (int i = 0; i < m; i++) {
            int index = rev[b[i]];
            if (to_shuffle.count(a[index]) != 0) {
                to_shuffle.erase(a[index]);
                c++;
                continue;
            }
            int c2 = to_shuffle.size();
            for (int j = last_index; j < index; j++) {
                to_shuffle.insert(a[j]);
                c2++;
            }
            last_index = index + 1;
            c += (long long)c2 * 2 + 1;
        }
        printf("%lld\n", c);
    }
}
