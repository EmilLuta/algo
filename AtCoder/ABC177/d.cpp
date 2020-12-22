#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<set<int>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        graph[x].insert(y);
        graph[y].insert(x);
    }
    set<int> seen;
    int answer = 0;
    vector<int> parent(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        /* printf("seen is = {"); */
        /* for (int x : seen) { */
        /*     printf("%d ", x); */
        /* } */
        /* printf("}\n"); */
        if (seen.count(i) != 0) {
            continue;
        }
        int size = 0;
        vector<int> q = {i};
        int index = 0;
        /* printf("searching for component at %d\n", i); */
        while (index < (int)q.size()) {
            int node = q[index];
            index++;
            if (seen.count(node) != 0) {
                continue;
            }
            seen.insert(node);
            size++;
            for (int child: graph[node]) {
                if (seen.count(child) == 0) {
                    q.push_back(child);
                    parent[child] = node;
                }
            }
        }
        answer = max(answer, size);
        /* printf("size is = %d\n", size); */
    }
    printf("%d\n", answer);
}
