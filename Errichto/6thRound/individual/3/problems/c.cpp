// https://codeforces.com/problemset/problem/1132/C

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    int answer = 0;
    vector<int> a(n + 2, 0);
    vector<pair<int, int>> p(q);
    for (int i = 0; i < q; i++) {
        int start, end;
        scanf("%d%d", &start, &end);
        a[start] += 1;
        a[end + 1] -= 1;
        p[i] = {start, end};
    }
    for (int i = 1; i <= n; i++) {
        a[i] += a[i - 1];
    }
    for (int i = 0; i < q; i++) {
        for (int j = p[i].first; j <= p[i].second; j++) {
            a[j]--;
        }
        for (int j = 0; j <= n; j++) {
            printf("a[%d] = %d\n", j, a[j]);
        }
        vector<int> uniq(n + 2, 0);
        int painted = 0;
        for (int j = 1; j <= n; j++) {
            if (a[j] > 0) {
                painted++;
            }
            if (a[j] == 1) {
                uniq[j] = 1;
            }
            printf("uniq[%d] = %d\n", j, uniq[j]);
        }
        vector<int> pref(n + 2, 0);
        for (int j = 1; j <= n; j++) {
            pref[j] = pref[j - 1] + uniq[j - 1];
            printf("pref[%d] = %d\n", j, pref[j]);
        }
        for (int j = i + 1; j < q; j++) {
            printf("i = %d; painted without i = %d; j = %d; painted without i and j = %d\n", i, painted, j, painted - (pref[p[j].second] - pref[p[j].first]));
            answer = max(answer, painted - (pref[p[j].second] - pref[p[j].first]));
        }

        for (int j = p[i].first; j <= p[i].second; j++) {
            a[j]++;
        }
    }
    printf("%d\n", answer);
}