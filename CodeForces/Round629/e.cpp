#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q_n;
    scanf("%d %d", &n, &q_n);
    set<pair<int, int>> graph;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a < b) {
            swap(a, b);
        }
        graph.insert({a, b});
    }
    vector<int> levels(n + 1, 0);
    vector<int> parents(n + 1, -1);
    vector<vector<int>> tree(n + 1);
    vector<int> q;
    q.push_back(1);
    int index = 0;
    while (index < (int)q.size()) {
        int node = q[index];
        index++;
        graph.find(node);
        /* for (int child : graph[node]) { */
        /*     if (levels[child] == 0 && child != 1) { */
        /*         rev_tree[child] = node; */
        /*         tree[node].push_back(child); */
        /*         levels[child] = levels[node] + 1; */
        /*         q.push_back(child); */
        /*     } */
        /* } */
    }
    /* string out; */
    /* for (int i = 0; i < q_n; i++) { */
    /*     int m; */
    /*     scanf("%d", &m); */
    /*     set<int> vertices; */
    /*     int m_d = -1; */
    /*     int m_v = -1; */
    /*     for (int j = 0; j < m; j++) { */
    /*         int node; */
    /*         scanf("%d", &node); */
    /*         if (levels[node] > m_d) { */
    /*             m_d = levels[node]; */
    /*             m_v = node; */
    /*         } */
    /*         vertices.insert(node); */
    /*     } */
    /*     int node = m_v; */
    /*     vertices.erase(node); */
    /*     set<int> p_vertices; */
    /*     for (int vertex : vertices) { */
    /*         if (vertex != 1) { */
    /*             p_vertices.insert(rev_tree[vertex]); */
    /*         } */
    /*     } */
    /*     while (node != -1) { */
    /*         if (p_vertices.count(node) != 0) { */
    /*             p_vertices.erase(node); */
    /*         } */
    /*         node = rev_tree[node]; */
    /*     } */
    /*     if ((int)p_vertices.size() == 0) { */
    /*         out += "YES\n"; */
    /*     } else { */
    /*         out += "NO\n"; */
    /*     } */
    /* } */
    /* cout << out; */
}
