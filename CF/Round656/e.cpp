#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        int n, m;
        scanf("%d%d", &n, &m);
        map<int, vector<int>> graph;
        vector<pair<int, int>> undirected;
        for (int i = 0; i < m; i++) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            if (a == 0) {
                undirected.push_back({b, c});
            } else {
                graph[b].push_back(c);
            }
        }
    }
}
