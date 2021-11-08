#include <bits/stdc++.h>

using namespace std;

void print_color(vector<char>& x) {
    printf("color = [");
    for (char b : x) {
        printf("%c ", b);
    }
    printf("]\n");
}

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
    vector<bool> seen(n, false);
    vector<char> color(n, 'x');
    for (int i = 0; i < n; i++) {
        if (!seen[i]) {
            vector<int> nodes = {i};
            int index = 0;
            seen[i] = true;
            color[i] = 'a';
            while (index < (int)nodes.size()) {
                int node = nodes[index];
                index++;
                char col = color[node];
                for (int child : graph[node]) {
                    if (color[child] == 'x') {
                        color[child] = col == 'a' ? 'b' : 'a';
                        if (!seen[child]) {
                            nodes.push_back(child);
                        }
                        seen[child] = true;
                        continue;
                    }
                    if (col == color[child]) {
                        printf("IMPOSSIBLE\n");
                        return 0;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", color[i] == 'a' ? 1 : 2);
    }
    printf("\n");
}
