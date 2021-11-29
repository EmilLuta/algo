#include <bits/stdc++.h>

using namespace std;

vector<bool> seen;
vector<int> parent;
vector<vector<int>> graph;
int loop_end = 0;
int loop_start = 0;

void dfs(int node) {
    if (loop_end != 0) {
        return;
    }
    seen[node] = true;
    for (int child : graph[node]) {
        if (seen[child] && parent[child] != node && parent[node] != child) {
            loop_end = node;
            loop_start = child;
            return;
        }
        if (!seen[child]) {
            parent[child] = node;
            dfs(child);
        }
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    seen.resize(n + 1, false);
    graph.resize(n + 1);
    parent.resize(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        dfs(i);
        if (loop_end != 0) {
            break;
        }
    }
    if (loop_end == 0) {
        printf("IMPOSSIBLE\n");
        return 0;
    }
    vector<int> answer = {loop_end};
    while (loop_start != loop_end) {
        answer.push_back(loop_start);
        loop_start = parent[loop_start];
    }
    answer.push_back(loop_start);
    printf("%d\n", (int)answer.size());
    for (int x : answer) {
        printf("%d ", x);
    }
    printf("\n");
}
