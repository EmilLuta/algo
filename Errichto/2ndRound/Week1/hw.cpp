#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

void initialize_vertices(set<int> &vertices, int n) {
    for (int i = 1; i < n + 1; i++) {
        vertices.insert(i);
    }
}

void dfs(int x, set<int> &vertices, set<pair<int, int>> not_edges, int &current_component) {
    printf("dfs start\n");
    auto it = vertices.upper_bound(x);
    while (it != vertices.end()) {
        int y = *it;
        it++;
        /* usleep(1000000); */
        /* cout << not_edges.count({x, y}) << endl; */
        /* cout << *vertices.upper_bound(10) << endl; */
        if (not_edges.count({x, y}) == 0) {
            current_component++;
            vertices.erase(y);
            /* printf("%d %d\n", x, y); */
            /* printf("ai de plm\n"); */
            dfs(y, vertices, not_edges, current_component);
        }
        /* printf("pisat\n"); */
    }
    printf("dfs end\n");
}

int main() {
    int n, m, components, current_component;
    scanf("%d %d", &n, &m);
    set<pair<int, int>> not_edges;
    set<int> vertices;
    vector<int> output;
    initialize_vertices(vertices, n);
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (x > y) {
            swap(x, y);
        }
        not_edges.insert({x, y});
    }

    while (vertices.upper_bound(0) != vertices.end()) {
        current_component = 0;
        int node = *vertices.upper_bound(0);
        vertices.erase(node);
        dfs(node, vertices, not_edges, current_component);
        printf("did I get out???");
        output.push_back(current_component);
        components++;
    }
    printf("%d\n", components);
    sort(output.begin(), output.end());
    for (auto o : output) {
        printf("%d ", o);
    }

    return 0;
}
