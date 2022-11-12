#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    vector<pair<int, int>> a(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].first);
        sum += a[i].first;
        a[i].second = -1;
    }
    int all = -1;
    int index_all = -1;
    for (int i = 0; i < q; i++) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            int index, val;
            scanf("%d%d", &index, &val);
            index--;
            if (index_all > a[index].second) {
                sum += val - all;
            } else {
                sum += val - a[index].first;
            }
            a[index] = {val, i};
        } else {
            int val;
            scanf("%d", &val);
            sum = n * (long long)val;
            all = val;
            index_all = i;
        }
        printf("%lld\n", sum);
    }
}
