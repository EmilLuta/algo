#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<bool> visited;
vector<vector<int>> graph;
map<string, vector<int>> color_output;

void dfs(int node, vector<vector<int>> &colors, int i) {
    visited[node] = true;
    for (int child : graph[node]) {
        if (!visited[child]) {
            int c1_fw_index = i % 3;
            int c2_fw_index = (i + 1) % 3;
            int c3_fw_index = (i + 2) % 3;
            int c1_bw_index = 2 - (i % 3);
            int c2_bw_index = 2 - ((i + 1) % 3);
            int c3_bw_index = 2 - ((i + 2) % 3);
            color_output["c1_fw"].push_back(colors[c1_fw_index][child]);
            color_output["c2_fw"].push_back(colors[c2_fw_index][child]);
            color_output["c3_fw"].push_back(colors[c3_fw_index][child]);
            color_output["c1_bw"].push_back(colors[c1_bw_index][child]);
            color_output["c2_bw"].push_back(colors[c2_bw_index][child]);
            color_output["c3_bw"].push_back(colors[c3_bw_index][child]);
            dfs(child, colors, ++i);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    vector<vector<int>> colors(3, vector<int>(n + 1));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &colors[i][j]);
        }
    }
    graph.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        x--;
        y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for (int i = 0; i < n; i++) {
        if (graph[i].size() > 2) {
            printf("-1\n");
            return 0;
        }
    }
    visited.resize(n + 1, false);
    vector<int> c;
    color_output["c1_fw"].push_back(colors[0][0]);
    color_output["c2_fw"].push_back(colors[1][0]);
    color_output["c3_fw"].push_back(colors[2][0]);
    color_output["c1_bw"].push_back(colors[2][0]);
    color_output["c2_bw"].push_back(colors[1][0]);
    color_output["c3_bw"].push_back(colors[0][0]);
    dfs(0, colors, 1);
    ll minimum = LLONG_MAX;
    string key;
    for (pair<string, vector<int>> entry : color_output) {
        ll current = 0;
        for (int i : entry.second) {
            current += (ll)i;
        }
        if (minimum > current) {
            minimum = current;
            key = entry.first;
        }
    }
    int start = 0;
    if ((char)key[1] == '1') {
        start = 0;
    } else if ((char)key[1] == '2') {
        start = 1;
    } else {
        start = 2;
    }
    printf("%lld\n", minimum);
    for (int i = 0; i < n; i++) {
        int value = (i + start) % 3 + 1;
        if (key == "c1_bw" || key == "c2_bw" || key == "c3_bw") {
            value = (2 - (i + start) % 3) + 1;
        }
        printf("%d ", value);
    }
}
