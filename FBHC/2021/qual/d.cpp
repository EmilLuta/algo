#include <bits/stdc++.h>

using namespace std;

void clear(vector<int>& costs, vector<int>& parent, map<int, vector<int>>& graph, int node) {
    while (node != 1) {
        vector<int> q = {node};
        int index = 0;
        set<int> seen = {1};
        while (index < (int)q.size()) {
            int c_node = q[index];
            index++;
            costs[c_node] = 0;
            seen.insert(c_node);
            for (int c_child : graph[c_node]) {
                if (seen.count(c_child) == 0) {
                    q.push_back(c_child);
                }
            }
        }
        node = parent[node];
    }
}

void print_cost(vector<int>& costs) {
    printf("costs = (");
    for (int i = 1; i < (int)costs.size(); i++) {
        printf("%d ", costs[i]);
    }
    printf(")\n");
}

void solve(int t) {
    int n;
    scanf("%d", &n);
    vector<int> c(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
    }
    map<int, vector<int>> graph;
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    vector<int> parent(n + 1, -1);
    parent[1] = 0;

    vector<int> q = {1};
    int index = 0;
    set<int> seen;
    vector<int> costs(n + 1, 0);
    while (index < (int)q.size()) {
        int node = q[index];
        index++;
        seen.insert(node);
        costs[node] = c[node] + costs[parent[node]];
        for (int child : graph[node]) {
            if (seen.count(child) == 0) {
                parent[child] = node;
                q.push_back(child);
            }
        }
    }
    int first_run = -1;
    int node = -1;
    for (int i = 1; i <= n; i++) {
        if (first_run < costs[i]) {
            first_run = costs[i];
            node = i;
        }
    }
    clear(costs, parent, graph, node);
    int answer = first_run;
    for (int i = 1; i <= n; i++) {
        answer = max(answer, first_run + max(0, costs[i] - costs[1]));
    }
    printf("Case #%d: %d\n", t, answer);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
