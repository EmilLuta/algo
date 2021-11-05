#include <bits/stdc++.h>

using namespace std;

const long long MIN = -1e14 - 7;

struct Node {
    long long max_pref; // XXXX|XX--
    long long max_suff; // --XX|XXXX
    long long max_subarray;
    long long sum;
};

Node merge(const Node& left, const Node& right) {
    long long max_pref, max_suff, max_subarray, sum;
    max_subarray = max(0ll, max(left.max_suff + right.max_pref, max(left.max_subarray, right.max_subarray)));
    max_pref = max(0ll, max(left.max_pref, left.sum + right.max_pref));
    max_suff = max(0ll, max(right.max_suff, right.sum + left.max_suff));
    sum = left.sum + right.sum;
    return Node{max_pref, max_suff, max_subarray, sum};
}

struct SegmentTree {
    int n;
    int b = 1;
    vector<Node> seg;

    void init(int size) {
        n = size;
        while (b < n) {
            b *= 2;
        }
        seg.resize(b * 2, Node{MIN, MIN, 0ll, MIN});
        for (int i = b; i < b + n; i++) {
            long long x;
            scanf("%lld", &x);
            seg[i] = Node{x, x, max(0ll, x), x};
        }
        for (int i = b - 1; i > 0; i--) {
            seg[i] = merge(seg[i * 2], seg[i * 2 + 1]);
        }
    }

    void update(int pos, long long val) {
        int node = pos + b - 1;
        seg[node] = Node{val, val, max(0ll, val), val};
        node /= 2;
        while (node > 0) {
            seg[node] = merge(seg[node * 2], seg[node * 2 + 1]);
            node /= 2;
        }
    }

    long long get_max_subarray() {
        return seg[1].max_subarray;
    }
};

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    SegmentTree tree;
    tree.init(n);
    for (int i = 0; i < m; i++) {
        int pos;
        long long val;
        scanf("%d%lld", &pos, &val);
        tree.update(pos, val);
        printf("%lld\n", tree.get_max_subarray());
    }
}
