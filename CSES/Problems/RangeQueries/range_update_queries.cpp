#include <bits/stdc++.h>

using namespace std;

void update(vector<long long>& seg, int node, int q_start, int q_end, int node_start, int node_end, int val) {
    if (node_end < q_start || node_start > q_end) {
        return;
    }
    if (q_start <= node_start && node_end <= q_end) {
        seg[node] += val;
        return;
    }
    int mid = (node_start + node_end) / 2;
    update(seg, node * 2, q_start, q_end, node_start, mid, val);
    update(seg, node * 2 + 1, q_start, q_end, mid + 1, node_end, val);
}

long long query(vector<long long>& seg, int node) {
    long long answer = 0;
    while (node > 0) {
        answer += seg[node];
        node /= 2;
    }
    return answer;
}

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    int b = 1;
    while (b < n) {
        b *= 2;
    }
    vector<long long> seg(b * 2);
    for (int i = b; i < b + n; i++) {
        scanf("%lld", &seg[i]);
    }
    for (int i = 0; i < q; i++) {
        int opt;
        scanf("%d", &opt);
        if (opt == 2) {
            int node;
            scanf("%d", &node);
            printf("%lld\n", query(seg, b + node - 1));
            continue;
        }
        int q_start, q_end, val;
        scanf("%d%d%d", &q_start, &q_end, &val);
        update(seg, 1, q_start, q_end, 1, b, val);
    }
}
