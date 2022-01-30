#include <bits/stdc++.h>

using namespace std;

int get_next(int i, vector<pair<int, int>>& a, int n) {
    while (i <= n && a[i].first == -1) {
        i++;
    }
    return i;
}

int main() {
    int n, l, k;
    scanf("%d%d%d", &n, &l, &k);
    vector<pair<int, int>> a(n + 1);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].first);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].second);
    }
    a[n] = {l, 0};
    while (k > 0) {
        k--;
        int i1 = 0;
        int i2 = get_next(i1 + 1, a, n);
        if (i2 == n) {
            break;
        }
        int i3 = get_next(i2 + 1, a, n);
        vector<pair<int, int>> dist;
        while (i3 <= n) {
            int initial = (a[i2].first - a[i1].first) * a[i1].second + (a[i3].first - a[i2].first) * a[i2].second;
            int on_remove = (a[i3].first - a[i1].first) * a[i1].second;
            int value = on_remove - initial;
            dist.push_back({value, i2});
            i1 = i2;
            i2 = i3;
            i3++;
            while (a[i3].first == -1) {
                i3++;
            }
        }
        sort(dist.begin(), dist.end());
        if (dist[0].first >= 0) {
            break;
        }
        a[dist[0].second] = {-1, -1};
    }
    int start = 0;
    long long answer = 0;
    int next = get_next(start, a, n);
    while (next <= n) {
        answer += (a[next].first - a[start].first) * a[start].second;
        start = next;
        next = get_next(start + 1, a, n);
    }
    printf("%lld\n", answer);
}
