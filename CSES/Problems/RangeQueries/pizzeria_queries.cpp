#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e9 + 7;

struct SegTree {
    int n = 0;
    int b = 1;
    vector<pair<long long, long long>> tree;

    void print() {
        assert(tree.size() != 0);
        for (int i = 0; i < b * 2; i++) {
            printf("(%lld %lld) ", tree[i].first, tree[i].second);
        }
        printf("\n");
    }

    void init(int x) {
        n = x;
        while (b < n) {
            b *= 2;
        }
        tree.resize(b * 2, {INF, INF});
        for (int i = b; i < b + n; i++) {
            long long v;
            scanf("%lld", &v);
            int index = i - b;
            tree[i] = {v - index, v + index};
        }
        for (int i = b - 1; i > 0; i--) {
            update_node(i);
        }
    }

    void update_node(int i) {
        tree[i] = {min(tree[i * 2].first, tree[i * 2 + 1].first), min(tree[i * 2].second, tree[i * 2 + 1].second)};
    }

    long long _query_low(int node, int q_left, int q_right, int node_left, int node_right) {
        if (node_left > q_right || q_left > node_right) {
            return INF;
        }
        if (q_left <= node_left && node_right <= q_right) {
            return tree[node].first;
        }
        int mid = (node_left + node_right) / 2;
        return min(_query_low(node * 2, q_left, q_right, node_left, mid), _query_low(node * 2 + 1, q_left, q_right, mid + 1, node_right));
    }

    long long _query_high(int node, int q_left, int q_right, int node_left, int node_right) {
        if (node_left > q_right || q_left > node_right) {
            return INF;
        }
        if (q_left <= node_left && node_right <= q_right) {
            return tree[node].second;
        }
        int mid = (node_left + node_right) / 2;
        return min(_query_high(node * 2, q_left, q_right, node_left, mid), _query_high(node * 2 + 1, q_left, q_right, mid + 1, node_right));
    }

    long long query(int k) {
        return min(_query_low(1, 1, k, 1, b) + k - 1, _query_high(1, k, n, 1, b) - k + 1);
    }

    void change(int x, long long val) {
        int i = b + x - 1;
        int index = x - 1;
        tree[i] = {val - index, val + index};
        i /= 2;
        while (i > 0) {
            update_node(i);
            i /= 2;
        }
    }
};

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    SegTree t;
    t.init(n);
    for (int i = 0; i < q; i++) {
        int opt;
        scanf("%d", &opt);
        if (opt == 1) {
            int index;
            long long val;
            scanf("%d%lld", &index, &val);
            t.change(index, val);
            continue;
        }
        int k;
        scanf("%d", &k);
        printf("%lld\n", t.query(k));
    }
}
