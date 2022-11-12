#include <bits/stdc++.h>

using namespace std;

struct SegTree {
    int n = 0;
    int base = 1;
    vector<int> seg;
    void init(int x) {
        n = x;
        while (base < n) {
            base *= 2;
        }
        seg.resize(base * 2, 0);
    }

    void update(int pos, int val) {
        int node = pos + base - 1;
        seg[node] = val;
        node /= 2;
        while (node > 0) {
            seg[node] = seg[node * 2] + seg[node * 2 + 1];
            node /= 2;
        }
    }

    int _query(int node, int q_start, int q_end, int node_start, int node_end) {
        if (q_start > node_end || q_end < node_start) {
            return 0;
        }
        if (q_start <= node_start && node_end <= q_end) {
            return seg[node];
        }
        int mid = (node_start + node_end) / 2;
        return _query(node * 2, q_start, q_end, node_start, mid) + _query(node * 2 + 1, q_start, q_end, mid + 1, node_end);
    }

    int query(int start, int end) {
        return _query(1, start, end, 1, base);
    }
};

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    SegTree row, col;
    vector<int> row_c(n + 1), col_c(n + 1);
    row.init(n + 1);
    col.init(n + 1);
    for (int i = 0; i < q; i++) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            int r, c;
            scanf("%d%d", &r, &c);
            row_c[r]++;
            col_c[c]++;
            row.update(r, 1);
            col.update(c, 1);
        } else if (type == 2) {
            int r, c;
            scanf("%d%d", &r, &c);
            row_c[r]--;
            col_c[c]--;
            if (row_c[r] == 0) {
                row.update(r, 0);
            }
            if (col_c[c] == 0) {
                col.update(c, 0);
            }
        } else {
            int r1, c1, r2, c2;
            scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
            if ((row.query(r1, r2) == r2 - r1 + 1) || col.query(c1, c2) == c2 - c1 + 1) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
            /* cout << "row fully covers => " << row.query(r1, r2) << " = " << r2 - r1 + 1<< endl; */
            /* cout << "col fully covers => " << col.query(c1, c2) << " = " << c2 - c1 + 1 << endl; */

            /* cout << endl; */
        }
    }
}
