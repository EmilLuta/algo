#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    map<char, int> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (char c : s) {
            m[c]++;
        }
    }
    for (pair<char, int> k_v : m) {
        if (k_v.second % n != 0) {
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
