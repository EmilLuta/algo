#include <bits/stdc++.h>

using namespace std;

struct SegTree {
    int b = 1;
    int n = 0;
    vector<int> seg;

    void init(int size) {
        n = size;
        while (b < n) {
            b *= 2;
        }
        seg.resize(b * 2, 0);
    }

    void update(int i, int val) {
        int node = b + i;
        seg[node] = val;
        while (node > 1) {
            node /= 2;
            seg[node] = seg[node * 2] + seg[node * 2 + 1];
        }
    }

    int rec_query(int node, int q_start, int q_end, int n_start, int n_end) {
        if (n_end < q_start || q_end < n_start) {
            return 0;
        }
        if (q_start <= n_start && n_end <= q_end) {
            return seg[node];
        }
        int mid = n_start + (n_end - n_start) / 2;
        return rec_query(node * 2, q_start, q_end, n_start, mid) + rec_query(node * 2 + 1, q_start, q_end, mid + 1, n_end);
    }

    int query(int start, int end) {
        return rec_query(1, start, end, 1, b);
    }

    void print() {
        printf("tree = [");
        for (int i = 0; i < b * 2; i++) {
            printf("%d ", seg[i]);
        }
        printf("]\n");
    }
};

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    SegTree seg;
    seg.init(n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    vector<vector<pair<int, int>>> queries(n + 1);
    for (int i = 0; i < q; i++) {
        int start, end;
        scanf("%d%d", &start, &end);
        queries[end].push_back({i, start});
    }
    map<int, int> last_index_for; // coordinate compression can reduce the need for a map
    vector<int> out(q);
    for (int i = 0; i < n; i++) {
        // Can reduce a bunch of those calls to the map
        if (last_index_for.count(a[i]) != 0) {
            seg.update(last_index_for[a[i]], 0);
        }
        last_index_for[a[i]] = i;
        seg.update(i, 1);
        for (pair<int, int> p : queries[i + 1]) {
            int start = p.second;
            int end = i + 1;
            int index = p.first;
            out[index] = seg.query(start, end);
        }
    }
    for (int i = 0; i < q; i++) {
        printf("%d\n", out[i]);
    }
}
