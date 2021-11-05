#include <bits/stdc++.h>

using namespace std;

struct Node {
    long long sum;
    long long max_pref;
};

Node merge(Node left, Node right) {
    return Node {left.sum + right.sum, max(0ll, max(left.max_pref, left.sum + right.max_pref))};
}

void init_seg_tree(vector<int>& a, vector<Node>& seg, int b, int n) {
    for (int i = b; i < b + n; i++) {
        seg[i] = Node{a[i - b], max(0, a[i - b])};
    }
    for (int i = b - 1; i > 0; i--) {
        Node left = seg[i * 2];
        Node right = seg[i * 2 + 1];
        seg[i] = merge(left, right);
    }
}

void update(vector<Node>& seg, int node, int val) {
    seg[node] = {val, val};
    while (node > 1) {
        if (node % 2 == 0) {
            seg[node / 2] = merge(seg[node], seg[node + 1]);
        } else {
            seg[node / 2] = merge(seg[node - 1], seg[node]);
        }
        node /= 2;
    }
}

long long query(vector<Node>& seg, int start, int end) {
    Node left = seg[start];
    if (start == end) {
        return left.max_pref;
    }
    Node right = seg[end];
    while (start + 1 < end) {
        if (start % 2 == 0) {
            left = merge(left, seg[start + 1]);
        }
        if (end % 2 == 1) {
            right = merge(seg[end - 1], right);
        }
        start /= 2;
        end /= 2;
    }
    Node answer = merge(left, right);
    return answer.max_pref;
}

void print_tree(vector<Node>& seg) {
    int n = seg.size();
    printf("seg = [");
    for (int i = 0; i < n; i++) {
        printf("(s = %lld, m_p = %lld), ", seg[i].sum, seg[i].max_pref);
    }
    printf("]\n");
}

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int b = 1;
    while (b < n) {
        b *= 2;
    }
    vector<Node> seg(b * 2, Node{0, 0});
    init_seg_tree(a, seg, b, n);
    for (int i = 0; i < q; i++) {
        int opt, x, y;
        scanf("%d%d%d", &opt, &x, &y);
        if (opt == 1) {
            update(seg, b + x - 1, y);
            continue;
        }
        printf("%lld\n", query(seg, x + b - 1, y + b - 1));
    }
}
