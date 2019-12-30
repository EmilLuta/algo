#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll INF = 1e18;

vector<vector<int>> graph;

void dfs(int node, int parent, vector<int> &order) {
    order.push_back(node);
    for (int child : graph[node]) {
        if (child != parent) {
             dfs(child, node, order);
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
    int leaf = -1;
    for (int i = 0; i < n; i++) {
        if (graph[i].size() > 2) {
            printf("-1\n");
            return 0;
        }
        if (graph[i].size() == 1) {
           leaf = i;
        }
    }
    assert(leaf != -1);
    vector<int> order;
    dfs(leaf, -1, order);
    assert(order[0] == leaf);
    assert(graph[order[0]].size() == 1);
    assert(graph[order[n - 1]].size() == 1);

    pair<ll, vector<int>> answer;
    answer.first = INF;
    for (int c1 : {0, 1, 2}) {
        for (int c2 : {0, 1, 2}) {
            if (c1 == c2) {
                continue;
            }
            int c3 = 0 + 1 + 2 - (c1 + c2);
            vector<int> three{c1, c2, c3};
            ll sum = 0;
            vector<int> orderMap (n);
            for(int i = 0; i < n; i++) { // a b c a b c _
                int node = order[i];
                int which_color = three[i % 3];
                sum += colors[which_color][node];
                orderMap[node] = which_color + 1;
            }
            answer = min(answer, make_pair(sum, orderMap));
        }
    }
    printf("%lld\n", answer.first);
    for(int x : answer.second) {
        printf("%d ", x);
    }
    printf("\n");
}
