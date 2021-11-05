#include <bits/stdc++.h>

using namespace std;

vector<bool> seen;
int n;
vector<vector<int>> graph;

void dfs(int node) {
    seen[node] = true;
    for (int child : graph[node]) {
        if (!seen[child]) {
            dfs(child);
        }
    }
}

int main() {
    int m;
    scanf("%d%d", &n, &m);
    graph.resize(n);
    seen.resize(n, false);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> components;
    for (int i = 0; i < n; i++) {
        if (!seen[i]) {
            dfs(i);
            components.push_back(i);
        }
    }
    printf("%d\n", (int)components.size() - 1);
    for (int i = 0; i < (int)components.size() - 1; i++) {
        printf("%d %d\n", components[i] + 1, components[i + 1] + 1);
    }
}
