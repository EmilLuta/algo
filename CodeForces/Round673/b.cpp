#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, t;
    scanf("%d%d", &n, &t);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    map<int, int> m_a, m_b;
    vector<int> answer(n);
    for (int i = 0; i < n; i++) {
        if (m_a[t - a[i]] <= m_b[t - a[i]]) {
            answer[i] = 1;
            m_a[a[i]]++;
        } else {
            answer[i] = 0;
            m_b[a[i]]++;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", answer[i]);
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
