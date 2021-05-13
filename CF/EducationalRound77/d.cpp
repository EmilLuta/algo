#include <bits/stdc++.h>

using namespace std;

int main() {
    int start = 1, end = 0, danger = 2;
    int m, n, k, t;
    scanf("%d%d%d%d", &m, &n, &k, &t);
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &a[i]);
    }
    vector<vector<int>> traps(k, vector<int>(3));
    for (int i = 0; i < k; i++) {
        scanf("%d%d%d", &traps[i][start], &traps[i][end], &traps[i][danger]);
    }
    sort(a.begin(), a.end());
    sort(traps.begin(), traps.end());
    int so_far = (traps[0][end] - traps[0][start]) * 3 + traps[0][start];
    if (t - so_far < n + 1 - traps[0][end]) {
        int max_danger = traps[0][danger];
        for (int i = 1; i < k; i++) {
            max_danger = max(max_danger, traps[i][danger]);
        }
        auto last = lower_bound(a.begin(), a.end(), max_danger);
        printf("%d\n", a.end() - last);
        return 0;
    }
    for (int i = 1; i < k; i++) {
        if (traps[i][start] == traps[i - 1][start]) {
            so_far -= 2 * (traps[i - 1][end] - traps[i - 1][start]);
            so_far += traps[i][end] - traps[i - 1][end];
            so_far += 2 * (traps[i][end] - traps[i][start]);
        } else if (traps[i][start] < traps[i - 1][end]) {
            so_far -= 2 * (traps[i - 1][end] - traps[i - 1][start]);
            so_far += traps[i][end] - traps[i - 1][end];
            so_far += 2 * (traps[i][end] - traps[i - 1][start]);
        } else {
            so_far += traps[i][start] - traps[i - 1][end];
            so_far += (traps[i][end] - traps[i][start]) * 3;
        }
        if (t - so_far < n + 1 - traps[i][end]) {
            int max_danger = traps[i][danger];
            for (int j = i + 1; j < k; j++) {
                max_danger = max(max_danger, traps[j][danger]);
            }
            auto last = lower_bound(a.begin(), a.end(), max_danger);
            printf("%d\n", a.end() - last);
            return 0;
        }
    }
    printf("%d\n", m);
}
