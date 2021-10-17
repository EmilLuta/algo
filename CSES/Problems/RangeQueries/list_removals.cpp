#include <bits/stdc++.h>

using namespace std;

int query(vector<int>& seg, int node, int b, int i) {
    if (node >= b) {
        int answer = node - b;
        seg[node] = 0;
        while (node > 1) {
            node /= 2;
            seg[node] = seg[node * 2] + seg[node * 2 + 1];
        }
        return answer;
    }
    if (seg[node * 2] >= i) {
        return query(seg, node * 2, b, i);
    }
    if (seg[node * 2 + 1] + seg[node * 2] >= i) {
        return query(seg, node * 2 + 1, b, i - seg[node * 2]);
    }
    return -1;
}

int main() {
    int n;
    scanf("%d", &n);
    int b = 1;
    while (b < n) {
        b *= 2;
    }
    vector<int> seg(b * 2, 0);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        seg[b + i] = 1;
    }
    for (int i = b - 1; i > 0; i--) {
        seg[i] = seg[i * 2] + seg[i * 2 + 1];
    }
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        int index = query(seg, 1, b, x);
        printf("%d ", a[index]);
    }
    printf("\n");
}
