#include <bits/stdc++.h>

using namespace std;

void dfs(int node, vector<vector<int>>& graph, set<int>& visited, vector<int>& leafs) {
    visited.insert(node);
    int out = 0;
    for (int c : graph[node]) {
        if (visited.count(c) == 0) {
            out++;
            dfs(c, graph, visited, leafs);
        }
    }
    if (out == 0) {
        leafs.push_back(node);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    vector<int> leafs;
    set<int> visited;
    dfs(1, graph, visited, leafs);
    if ((int)graph[1].size() == 1) {
        leafs.push_back(1);
    }
    int l_n = leafs.size();
    int k = (l_n + 1) / 2;
    printf("%d\n", k);
    for (int i = 0; i < k; i++) {
        printf("%d %d\n", leafs[i], leafs[(i + k) % l_n]);
    }
}
