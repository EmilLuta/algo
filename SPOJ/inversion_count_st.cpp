#include <bits/stdc++.h>

using namespace std;

long long query(vector<long long>& seg, int node, int q_start, int q_end, int n_start, int n_end) {
    if (n_end < q_start || q_end < n_start) {
        return 0;
    }
    if (q_start <= n_start && n_end <= q_end) {
        return seg[node];
    }
    int mid = (n_start + n_end) / 2;
    return query(seg, node * 2, q_start, q_end, n_start, mid) + query(seg, node * 2 + 1, q_start, q_end, mid + 1, n_end);
}

void solve() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    vector<int> b(a.begin(), a.end());
    sort(b.begin(), b.end());
    map<int, int> m;
    int compressed = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            m[b[i]] = compressed;
            compressed++;
            continue;
        }
        if (b[i] == b[i - 1]) {
            continue;
        }
        m[b[i]] = compressed;
        compressed++;
    }
    int base = 1;
    while (base < compressed) {
        base *= 2;
    }
    vector<long long> seg(base * 2, 0);
    long long answer = 0;
    for (int i = 0; i < n; i++) {
        int node = base + m[a[i]];
        seg[node]++;
        while (node > 1) {
            node /= 2;
            seg[node] = seg[node * 2] + seg[node * 2 + 1];
        }
        answer += query(seg, 1, m[a[i]] + 2, compressed, 1, base);
    }
    printf("%lld\n", answer);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        solve();
        t--;
    }
}
