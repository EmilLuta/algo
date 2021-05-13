#include <bits/stdc++.h>

using namespace std;

void solve() {
    string a;
    cin >> a;
    int n = a.size(), pl = 0, mi = 0, s = 0;
    map<int ,int> m;
    for (int i = 0; i < n; i++) {
        if (a[i] == '+') {
            pl++;
            s++;
        } else {
            mi++;
            s--;
        }
        if (s < 0 && m.count(s) == 0) {
            m[s] = i + 1;
        }
    }
    long long answer = 0;
    for (int i = m.begin()->first; i < 0; i++) {
        answer = answer + (long long)m[i];
    }
    printf("%lld\n", answer + (long long)n);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
