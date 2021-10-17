#include <bits/stdc++.h>

using namespace std;

int query(vector<int>& seg, int b, int v) {
    int node = 1;
    if (seg[node] < v) {
        return 0;
    }
    while (node < b) {
        if (seg[node * 2] >= v) {
            node = node * 2;
            continue;
        }
        if (seg[node * 2 + 1] >= v) {
            node = node * 2 + 1;
            continue;
        }
        return 0;
    }
    int answer = node - b + 1;
    seg[node] -= v;
    while (node > 1) {
        node /= 2;
        seg[node] = max(seg[node * 2], seg[node * 2 + 1]);
    }
    return answer;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int b = 1;
    while (b < n) {
        b *= 2;
    }
    vector<int> seg(b * 2, 0);
    for (int i = b; i < b + n; i++) {
        scanf("%d", &seg[i]);
    }
    for (int i = b - 1; i > 0; i--) {
        seg[i] = max(seg[i * 2], seg[i * 2 + 1]);
    }
    for (int i = 0; i < m; i++) {
        int v;
        scanf("%d", &v);
        printf("%d ", query(seg, b, v));
    }
    printf("\n");
}
