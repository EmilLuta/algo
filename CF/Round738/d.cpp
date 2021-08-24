#include <bits/stdc++.h>

using namespace std;

// ios::sync_with_stdio(0);
// cin.tie(0);

# define deb_v(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << item << " "; \
    cerr << ")\n";

# define deb(x) cerr << #x << " = " << x << "\n";

# define deb_v_p(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << "(" << item.first << ", " << item.second << ") "; \
    cerr << ")\n";

void dfs(int i, map<int, set<int>> &comp, map<int, vector<int>> &a, set<int> &seen) {
    vector<int> q = {i};
    set<int> curr;
    int index = 0;
    while (index < (int)q.size()) {
        int node = q[index];
        index++;
        seen.insert(node);
        curr.insert(node);
        for (int child : a[node]) {
            if (seen.count(child) == 0) {
                q.push_back(child);
            }
        }
    }
    comp[i] = curr;
}

void print_forest(string name, map<int, set<int>> forest) {
    cout << "In forest " << name << " we got\n";
    for (auto p : forest) {
        printf("%d: ", p.first);
        for (int x : p.second) {
            printf("%d ", x);
        }
        printf("\n");
    }
}

void update(vector<int>& node_belongs_to, map<int, set<int>> &comp) {
    for (auto p : comp) {
        int node = p.first;
        node_belongs_to[node] = node;
        for (int x : p.second) {
            node_belongs_to[x] = node;
        }
    }
}

void merge(int x, int y, vector<int>& node_belongs_to, map<int, set<int>> &comp) {
    int x_lead = node_belongs_to[x];
    int y_lead = node_belongs_to[y];
    set<int> for_x = comp[x_lead];
    set<int> for_y = comp[y_lead];
    if (for_x.size() < for_y.size()) {
        swap(for_x, for_y);
        swap(x_lead, y_lead);
    }
    for (int val : for_y) {
        node_belongs_to[val] = x_lead;
        comp[x_lead].insert(val);
    }
    comp.erase(y_lead);
}

int main() {
    int n, m1, m2;
    scanf("%d%d%d", &n, &m1, &m2);
    map<int, vector<int>> a, b;
    for (int i = 0; i < m1; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for (int i = 0; i < m2; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        b[x].push_back(y);
        b[y].push_back(x);
    }
    map<int, set<int>> a_comp, b_comp;
    set<int> seen_a, seen_b;
    for (int i = 1; i <= n; i++) {
        if (seen_a.count(i) == 0) {
            dfs(i, a_comp, a, seen_a);
        }
        if (seen_b.count(i) == 0) {
            dfs(i, b_comp, b, seen_b);
        }
    }
    vector<int> node_in_a_belongs_to(n + 1);
    vector<int> node_in_b_belongs_to(n + 1);
    update(node_in_a_belongs_to, a_comp);
    update(node_in_b_belongs_to, b_comp);
    /* print_forest("Mocha", a_comp); */
    /* print_forest("Diana", b_comp); */
    vector<pair<int, int>> output;
    for (int x = 1; x <= n; x++) {
        for (int y = x + 1; y <= n; y++) {
            if (node_in_a_belongs_to[x] == node_in_a_belongs_to[y] || node_in_b_belongs_to[x] == node_in_b_belongs_to[y]) {
                continue;
            }
            merge(x, y, node_in_a_belongs_to, a_comp);
            merge(x, y, node_in_b_belongs_to, b_comp);
            output.push_back({x, y});
        }
    }
    int x = output.size();
    printf("%d\n", x);
    for (int i = 0; i < x; i++) {
        printf("%d %d\n", output[i].first, output[i].second);
    }
}
