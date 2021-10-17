#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e9 + 5;

int query(int node, vector<int>& seg, int q_start, int q_end, int node_start, int node_end) {
    if (node_end < q_start || node_start > q_end) {
        return MAX;
    }
    if (q_start <= node_start && node_end <= q_end) {
        return seg[node];
    }
    int mid = (node_start + node_end) / 2;
    return min(query(node * 2, seg, q_start, q_end, node_start, mid), query(node * 2 + 1, seg, q_start, q_end, mid + 1, node_end));
}

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    int base = 1;
    while (base < n) {
        base *= 2;
    }
    vector<int> seg(base * 2, MAX);
    for (int i = base; i < base + n; i++) {
        scanf("%d", &seg[i]);
    }
    for (int i = base - 1; i > 0; i--) {
        seg[i] = min(seg[i * 2], seg[i * 2 + 1]);
    }
    for (int i = 0; i < q; i++) {
        int q_start, q_end;
        scanf("%d%d", &q_start, &q_end);
        printf("%d\n", query(1, seg, q_start, q_end, 1, base));
    }
}
