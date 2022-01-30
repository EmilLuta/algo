#include <bits/stdc++.h>

using namespace std;

void find(int start, int end, set<pair<int, int>>& s) {
    if (start == end) {
        printf("%d %d %d\n", start, end, end);
        return;
    }
    for (int i = start; i <= end; i++) {
        if (i == start) {
            if (s.count({i + 1, end}) == 1) {
                printf("%d %d %d\n", start, end, i);
                find(i + 1, end, s);
                return;
            }
        }
        if (i == end) {
            if (s.count({start, i - 1}) == 1) {
                printf("%d %d %d\n", start, end, i);
                find(start, i - 1, s);
                return;
            }
        }
        if (s.count({start, i - 1}) == 1 && s.count({i + 1, end}) == 1) {
            printf("%d %d %d\n", start, end, i);
            find(start, i - 1, s);
            find(i + 1, end, s);
            return;
        }
    }
}

void solve() {
    int n;
    scanf("%d", &n);
    set<pair<int, int>> s;
    for (int i = 0; i < n; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        s.insert({l, r});
    }
    find(1, n, s);
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
