#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        m[a[i]] = min(m[a[i]] + 1, 2);
    }
    int mid_val = -1;
    for (pair<int, int> p : m) {
        if (p.second == 1) {
            mid_val = p.first;
        }
    }
    if (mid_val == -1) {
        mid_val = a[n - 1];
    }
    m[mid_val]--;
    if (m[mid_val] == 0) {
        m.erase(mid_val);
    }
    int bw = 1;
    int fw = 1;
    for (pair<int, int> p : m) {
        int got = p.second;
        if (bw < fw) {
            bw++;
            if (got == 2) {
                fw++;
            }
        } else {
            fw++;
            if (got == 2) {
                bw++;
            }
        }
    }
    printf("%d\n", min(bw, fw));
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        solve();
        t--;
    }
}
