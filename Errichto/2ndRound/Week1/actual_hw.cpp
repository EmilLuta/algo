#include <bits/stdc++.h>

using namespace std;

void initialize_vertices(set<int> &vertices, int n) {
    for (int i = 1; i < n + 1; i++) {
        vertices.insert(i);
    }
}

set<pair<int,int>> not_edges;
set<int> vertices;

void dfs(int x, int &current_component) {
    current_component++;
    vector<int> to_remove;
    auto it = vertices.upper_bound(x);
    for (int y : vertices) {
        if (not_edges.count({x, y}) == 0) { // how many times can this be true?
            to_remove.push_back(y);
        }
    }
    for (int vertex : to_remove) {
        vertices.erase(vertex);
    }
    for (int vertex : to_remove) {
        dfs(vertex, current_component);   
    }
}

int main() {
    
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> components;
    initialize_vertices(vertices, n);
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        not_edges.insert({x, y});
        not_edges.insert({y, x});
    }

    while (!vertices.empty()) {
        int current_component = 0;
        int node = *vertices.begin();
        vertices.erase(node);
        dfs(node, current_component);
        components.push_back(current_component);
    }
    printf("%d\n", components.size());
    sort(components.begin(), components.end());
    for (int o : components) {
        printf("%d ", o);
    }

    return 0;
}






