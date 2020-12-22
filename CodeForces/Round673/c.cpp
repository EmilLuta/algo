#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    map<int, vector<int>> m_i;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        m_i[a[i]].push_back(i);
    }
    map<int, int> m_d;
    for (auto& k_v : m_i) {
        vector<int>& diffs = k_v.second;
        sort(diffs.begin(), diffs.end());
        int d_n = diffs.size();
        /* if (d_n == 1) { */
        /*     int x = diffs[0]; */
        /*     if (x < n / 2) { */
        /*         x = n - x - 1; */
        /*     } */
        /*     m_d[x + 1].insert(k_v.first); */
        /*     continue; */
        /* } */
        int max_gap = 0;
        for (int i = 1; i < d_n; i++) {
            max_gap = max(max_gap, diffs[i] - diffs[i - 1]);
        }
        int x = max(max(max_gap, diffs[0] + 1), n - diffs[d_n - 1]);
        if (m_d.count(x) == 0) {
            m_d[x] = k_v.first;
        } else {
            m_d[x] = min(m_d[x], k_v.first);
        }
    }
    int answer = -1;
    for (int i = 1; i <= n; i++) {
        if (m_d.count(i) != 0) {
            if (answer != -1) {
                answer = min(answer, m_d[i]);
            } else {
                answer = m_d[i];
            }
        }
        printf("%d ", answer);
    }
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
