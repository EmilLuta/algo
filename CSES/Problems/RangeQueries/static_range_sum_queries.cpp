#include <bits/stdc++.h>

using namespace std;

long long query(vector<long long>& seg, int node, int q_start, int q_end, int node_start, int node_end) {
    if (q_start > node_end || q_end < node_start) {
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
    int base = 1;
    while (base < n) {
        base *= 2;
    }
    vector<long long> seg(base * 2, 0);
    for (int i = base; i < base + n; i++) {
        scanf("%lld", &seg[i]);
    }
    for (int i = base - 1; i >= 1; i--) {
        seg[i] = seg[i * 2] + seg[i * 2 + 1];
    }
    for (int i = 0; i < q; i++) {
        int q_start, q_end;
        scanf("%d%d", &q_start, &q_end);
        printf("%lld\n", query(seg, 1, q_start, q_end, 1, base));
    }

}
