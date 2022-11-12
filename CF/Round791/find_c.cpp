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

struct BF {
    int n;
    vector<bool> row;
    vector<bool> col;
    void init(int x) {
        n = x;
        row.resize(n + 1, false);
        col.resize(n + 1, false);
    }

    void add(int r, int c) {
        row[r] = true;
        col[c] = true;
    }

    void remove(int r, int c) {
        row[r] = false;
        col[c] = false;
    }

    bool query(int r1, int c1, int r2, int c2) {
        bool row_good = true;
        for (int r = r1; r <= r2; r++) {
            if (!row[r]) {
                row_good = false;
            }
        }
        bool col_good = true;
        for (int c = c1; c <= c2; c++) {
            if (!col[c]) {
                col_good = false;
            }
        }
        return row_good || col_good;
    }
};

int main() {
    int iterations = 0;
    while (true) {
        vector<vector<int>> iteration_data;
        int n = rand() % 10000 + 1;
        int q = rand() % 10 + 1;
        iteration_data.push_back({n, q});
        SegTree row, col;
        BF bf;
        bf.init(n);
        row.init(n + 1);
        col.init(n + 1);
        for (int i = 0; i < q; i++) {
            int type = rand() % 6;
            if (type == 1) {
                int r = rand() % n + 1, c = rand() % n + 1;
                row.update(r, 1);
                col.update(c, 1);
                bf.add(r, c);
            } else if (type == 2) {
                int r = rand() % n + 1, c = rand() % n + 1;
                row.update(r, 0);
                col.update(c, 0);
                bf.remove(r, c);
            } else {
                int r1 = rand() % n + 1;
                int c1 = rand() % n + 1;
                int r2 = rand() % n + 1;
                int c2 = rand() % n + 1;
                if (r1 > r2) {
                    swap(r1, r2);
                }
                if (c1 > c2) {
                    swap(c1, c2);
                }
                bool bf_answer = bf.query(r1, c1, r2, c2);
                bool my_answer = (row.query(r1, r2) == r2 - r1 + 1) || col.query(c1, c2) == c2 - c1 + 1;
                if (bf_answer != my_answer) {
                    cout << "found culprit\n";
                    break;
                }
            }
        }
        iterations++;
        if (iterations % 100 == 0) {
            cout << iterations << endl;
        }
    }
}
