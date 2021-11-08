#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        x--;
        y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    vector<int> from(n, -1);
    set<pair<int, int>> nodes = {{0, 0}};
    while ((int)nodes.size() > 0) {
        pair<int, int> p = *nodes.begin();
        nodes.erase(p);
        int node = p.second;
        int cost = p.first;
        for (int child : graph[node]) {
            if (from[child] == -1) {
                from[child] = node;
                nodes.insert({cost + 1, child});
            }
        }
    }
    if (from[n - 1] == -1) {
        printf("IMPOSSIBLE\n");
        return 0;
    }
    vector<int> out;
    int node = n - 1;
    while (node != 0) {
        out.push_back(node);
        node = from[node];
    }
    out.push_back(0);
    printf("%d\n", (int)out.size());
    for (int i = out.size() - 1; i >= 0; i--) {
        printf("%d ", out[i] + 1);
    }
    printf("\n");

}
