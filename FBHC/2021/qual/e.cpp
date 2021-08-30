#include <bits/stdc++.h>

using namespace std;

void print_cost(string name, vector<int>& costs) {
    cout << name << " = (";
    for (int i = 1; i < (int)costs.size(); i++) {
        printf("%d ", costs[i]);
    }
    printf(")\n");
}

void parse_component(map<int, set<int>>& graph, vector<int>& parent, vector<int>& costs, int n, int start, set<int>& seen, vector<int>& c) {
    vector<int> q = {start};
    int index = 0;
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
}

void parse_structure(map<int, set<int>>& graph, vector<int>& parent, vector<int>& costs_one, vector<int>& costs_two, int n, vector<int>& c) {
    set<int> seen;
    parent[1] = 0;
    parse_component(graph, parent, costs_one, n, 1, seen, c);
    for (int i = 2; i <= n; i++) {
        if (seen.count(i) == 0) {
            parent[i] = 0;
            parse_component(graph, parent, costs_two, n, i, seen, c);
        }
    }
}

void solve(int t) {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> c(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
    }
    map<int, set<int>> graph;
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        graph[x].insert(y);
        graph[y].insert(x);
    }
    int answer = 0;
    while (k > 0) {
        vector<int> parent(n + 1, -1);
        vector<int> costs_one(n + 1, 0), costs_two(n + 1, 0);
        parse_structure(graph, parent, costs_one, costs_two, n, c);
        bool stop = true;
        for (int i = 1; i <= n; i++) {
            if (costs_one[i] != 0 || costs_two[i] != 0) {
                stop = false;
            }
        }
        if (stop) {
            break;
        }
        int c_one = find_biggest_one(costs_one);
        int c_two = find_biggest_two(costs_two);
        print_cost("costs one", costs_one);
        print_cost("costs two", costs_two);
    }
    /* vector<int> parent(n + 1, -1); */
    /* vector<int> costs_one(n + 1, 0); */
    /* set<int> */
    /* parent[1] = 0; */
    /* for (int i = 1; i <= n; i++) { */
    /*     if (seen.count(i) == 0) { */
    /*         parse_component(parent, graph, costs, seen, n, i); */
    /*     } */
    /* } */
    /* create_data(parent, graph, costs, seen) */
    /* vector<int> q = {1}; */
    /* int index = 0; */
    /* set<int> seen; */
    /* vector<int> costs(n + 1, 0); */
    /* while (index < (int)q.size()) { */
    /*     int node = q[index]; */
    /*     index++; */
    /*     seen.insert(node); */
    /*     costs[node] = c[node] + costs[parent[node]]; */
    /*     for (int child : graph[node]) { */
    /*         if (seen.count(child) == 0) { */
    /*             parent[child] = node; */
    /*             q.push_back(child); */
    /*         } */
    /*     } */
    /* } */
    /* int first_run = -1; */
    /* int node = -1; */
    /* for (int i = 1; i <= n; i++) { */
    /*     if (first_run < costs[i]) { */
    /*         first_run = costs[i]; */
    /*         node = i; */
    /*     } */
    /* } */
    /* clear(costs, parent, graph, node); */
    /* int answer = first_run; */
    /* for (int i = 1; i <= n; i++) { */
    /*     answer = max(answer, first_run + max(0, costs[i] - costs[1])); */
    /* } */
    printf("Case #%d: %d\n", t, answer);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
