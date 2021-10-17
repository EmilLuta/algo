#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e9 + 5;

void update(vector<int>& seg, int node, int val) {
    seg[node] = val;
    node /= 2;
    while (node > 0) {
        seg[node] = min(seg[node * 2], seg[node * 2 + 1]);
        node /= 2;
    }
}

int query(vector<int>& seg, int node, int q_start, int q_end, int node_start, int node_end) {
    if (q_end < node_start || q_start > node_end) {
        return MAX;
    }
    if (q_start <= node_start && node_end <= q_end) {
        return seg[node];
    }
    int mid = (node_start + node_end) / 2;
    return min(query(seg, node * 2, q_start, q_end, node_start, mid), query(seg, node * 2 + 1, q_start, q_end, mid + 1, node_end));
}

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    int base = 1;
    while (base < n) {
        base *= 2;
    }
    vector<int> seg(2 * base, MAX);
    for (int i = base; i < base + n; i++) {
        scanf("%d", &seg[i]);
    }
    for (int i = base - 1; i > 0; i--) {
        seg[i] = min(seg[i * 2], seg[i * 2 + 1]);
    }
    for (int i = 0; i < q; i++) {
        int opt, a, b;
        scanf("%d%d%d", &opt, &a, &b);
        if (opt == 1) {
            update(seg, base + a - 1, b);
            continue;
        }
        printf("%d\n", query(seg, 1, a, b, 1, base));
    }
}
