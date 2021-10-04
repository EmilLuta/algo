#include <bits/stdc++.h>

using namespace std;

void solve(int t) {
    int n;
    scanf("%d", &n);
    vector<int> q;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++) {
        int c;
        scanf("%d", &c);
        if (c == 0) {
            q.push_back(i);
        }
        for (int j = 0; j < c; j++) {
            int x;
            scanf("%d", &x);
            x--;
            a[x].push_back(i);
        }
    }
    if ((int)q.size() == 0) {
        printf("-1\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        printf("%d = [", i);
        for (int j = 0; j < (int)a[i].size(); j++) {
            printf("%d ", a[i][j]);
        }
        printf("]\n");
    }
    set<int> seen;
    vector<int> levels(n, 1);
    int i = 0;
    while (i < (int)q.size()) {
        int node = q[i];
        printf("going through %d\n", node);
        i++;
        if (seen.count(node)) {
            printf("-1\n");
            return;
        }
        seen.insert(node);
        for (int child : a[node]) {
            if (seen.count(node)) {
                printf("-1\n");
                return;
            }
            levels[child] = levels[node] + 1;
            q.push_back(child);
        }
    }
    for (int j = 0; j < n; j++) {
        printf("%d ", levels[i]);
    }
    printf("\n");
    int answer = 0;
    for (int x : levels) {
        answer = max(answer, x);
    }
    printf("%d\n", answer);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(t);
    }
}
