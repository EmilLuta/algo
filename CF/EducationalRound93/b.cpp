#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    map<int, int> m;
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            m[c]++;
            c = 0;
        } else {
            c++;
        }
    }
    if (c != 0) {
        m[c]++;
    }
    int answer = 0;
    bool first = true;
    auto it = m.rbegin();
    while (it != m.rend()) {
        int to_go = it->second;
        while (to_go > 0) {
            if (first) {
                answer += it->first;
            }
            to_go--;
            first = !first;

        }
        it++;
    }
    printf("%d\n", answer);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
