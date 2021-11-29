#include <bits/stdc++.h>

using namespace std;

const int N = 1048576;

struct SegTree {
    vector<int> seg;
    int b = N;

    void init() {
        seg.resize(N * 2, -1);
        for (int i = b; i < b + N; i++) {
            seg[i] = i - b;
        }
        for (int i = b - 1; i > 0; i--) {
            seg[i] = min(seg[i * 2], seg[i * 2 + 1]);
        }
    }

    void update(int node) {
        seg[node] = 1e9;
        node /= 2;
        while (node > 0) {
            seg[node] = min(seg[node * 2], seg[node * 2 + 1]);
            node /= 2;
        }
    }

    int query(int node, int q_start, int q_end, int n_start, int n_end) {
        if (q_end < n_start || q_start > n_end) {
            return 1e9;
        }
        if (q_start <= n_start && n_end <= q_end) {
            return seg[node];
        }
        int mid = (n_start + n_end) / 2;
        return min(query(node * 2, q_start, q_end, n_start, mid), query(node * 2 + 1, q_start, q_end, mid + 1, n_end));

    }
};

int main() {
    vector<long long> a(N, -1);
    int q;
    scanf("%d", &q);
    SegTree seg;
    seg.init();
    for (int i = 0; i < q; i++) {
        int t;
        long long x;
        scanf("%d%lld", &t, &x);
        if (t == 1) {
            int v = x % N;
            int pos = seg.query(1, v, seg.b, 0, seg.b - 1);
            if (pos == 1e9) {
                pos = seg.query(1, 0, v, 0, seg.b - 1);
            }
            a[pos] = x;
            seg.update(seg.b + pos);
        } else {
            printf("%lld\n", a[x % N]);
        }
    }
}
