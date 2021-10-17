#include <bits/stdc++.h>

using namespace std;

struct Query {
    char type;
    int a;
    int b;
};

void update(vector<int>& seg, int node, int val) {
    seg[node] += val;
    node /= 2;
    while (node > 0) {
        seg[node] = seg[node * 2] + seg[node * 2 + 1];
        node /= 2;
    }
}

int query(vector<int>& seg, int node, int q_start, int q_end, int node_start, int node_end) {
    if (node_end < q_start || q_end < node_start) {
        return 0;
    }
    if (q_start <= node_start && node_end <= q_end) {
        return seg[node];
    }
    int mid = (node_start + node_end) / 2;
    return query(seg, node * 2, q_start, q_end, node_start, mid) + query(seg, node * 2 + 1, q_start, q_end, mid + 1, node_end);
}

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    vector<Query> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].type >> queries[i].a >> queries[i].b;
    }
    vector<int> all(a.begin(), a.end());
    for (int i = 0; i < q; i++) {
        all.push_back(queries[i].b);
        if (queries[i].type == '?') {
            all.push_back(queries[i].a);
        }
    }
    sort(all.begin(), all.end());
    vector<int>::iterator it = unique(all.begin(), all.end());
    all.resize(it - all.begin());
    int s = all.size();
    int b = 1;
    while (b < s) {
        b *= 2;
    }
    vector<int> seg(b * 2, 0);
    for (int i = 0; i < n; i++) {
        int node = lower_bound(all.begin(), all.end(), a[i]) - all.begin() + b;
        seg[node] += 1;
    }
    for (int i = b - 1; i > 0; i--) {
        seg[i] = seg[i * 2] + seg[i * 2 + 1];
    }
    for (Query x : queries) {
        if (x.type == '!') {
            int i = x.a - 1;
            int old_salary = a[i];
            int new_salary = x.b;
            int old_node = lower_bound(all.begin(), all.end(), old_salary) - all.begin() + b;
            int new_node = lower_bound(all.begin(), all.end(), new_salary) - all.begin() + b;
            a[i] = new_salary;
            update(seg, old_node, -1);
            update(seg, new_node, 1);
            continue;
        }
        int start = lower_bound(all.begin(), all.end(), x.a) - all.begin() + 1;
        int end = lower_bound(all.begin(), all.end(), x.b) - all.begin() + 1;
        printf("%d\n", query(seg, 1, start, end, 1, b));
    }
}
