#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> get_tree(const vector<vector<int>>& graph, int n) {
    vector<vector<int>> tree(n + 1);
    vector<int> q = {1};
    int index = 0;
    set<int> seen;
    while (index < (int)q.size()) {
        int node = q[index];
        index++;
        seen.insert(node);
        for (int child: graph[node]) {
            if (seen.count(child) == 0) {
                tree[node].push_back(child);
                q.push_back(child);
            }
        }
    }
    return tree;
}

void get_subsizes(const vector<vector<int>>& tree, vector<int>& subsizes, int node) {
    subsizes[node] = 1;
    for (int child : tree[node]) {
        get_subsizes(tree, subsizes, child);
        subsizes[node] += subsizes[child];
    }
}

void solve() {
    int n;
    scanf("%d", &n);
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    vector<vector<int>> tree = get_tree(graph, n);
    vector<int> subsizes(n + 1);
    get_subsizes(tree, subsizes, 1);
    vector<int> centroids;
    int centroid_val = n;
    for (int i = 1; i <= n; i++) {
        int current = n - subsizes[i];
        for (int child : tree[i]) {
            current = max(current, subsizes[child]);
        }
        /* printf("current = %d\n", current); */
        if (current <= centroid_val) {
            if (current < centroid_val) {
                centroids.resize(0);
            }
            centroids.push_back(i);
            centroid_val = current;
        }
    }
    assert((int)centroids.size() <= 2);
    if ((int)centroids.size() == 1) {
        printf("%d %d\n%d %d\n", centroids[0], tree[centroids[0]][0], centroids[0], tree[centroids[0]][0]);
        return;
    }
    for (int child : graph[centroids[0]]) {
        if (child != centroids[1]) {
            printf("%d %d\n%d %d\n", centroids[0], child, centroids[1], child);
            return;
        }
    }
    /* printf("centroid value = %d\n", centroid_val); */
    /* printf("centroid nodes = ["); */
    /* for (int node : centroids) { */
    /*     printf("%d, ", node); */
    /* } */
    /* printf("]\n"); */
    /* for (int i = 1; i <= n; i++) { */
    /*     printf("subsize of %d is %d\n", i, subsizes[i]); */
    /* } */
    /* for (int i = 1; i <= n; i++) { */
    /*     printf("node %d = [", i); */
    /*     for (int j = 0; j < tree[i].size(); j++) { */
    /*         printf("%d, ", tree[i][j]); */
    /*     } */
    /*     printf("]\n"); */
    /* } */
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
