// https://codeforces.com/problemset/problem/920/E

#include <bits/stdc++.h>
using namespace std;

int n, m, current_component;
void dfs(int x, vector<bool> &visited, set<pair<int, int>> &non_edges) {
    current_component++;
    for (int y = 1; y < n + 1; y++) {
        if (!((non_edges.count({x, y}) == 1) || (non_edges.count({y, x}) == 1)) && !visited[y]) {
            visited[y] = true;
            dfs(y, visited, non_edges);
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    vector<bool> visited(n + 2);
    set<pair<int, int>> non_edges;
    set<int> nodes_left;
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (x > y) {
            swap(x, y);
        }
        non_edges.insert({x, y});
    }
    int components = 0;
    vector<int> output;
    for(int i = 1; i < n + 1; i++) {
        if (!visited[i]) {
            current_component = 0;
            visited[i] = true;
            dfs(i, visited, non_edges);
            components++;
            output.push_back(current_component);
        }
    }
    printf("%d\n", components);
    sort(output.begin(), output.end());
    for (auto o : output) {
        printf("%d ", o);
    }
    return 0;
}
