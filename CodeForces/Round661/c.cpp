#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    set<int> sums;
    map<int, int> counter;
    for (int i = 0; i < n; i++) {
        counter[a[i]]++;
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            sums.insert(a[i] + a[j]);
        }
    }
    int answer = 0;
    for (int s: sums) {
        map<int, int> c(counter);
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (c.count(a[i]) != 0 && c.count(s - a[i]) != 0) {
                if (a[i] == s - a[i] && c[a[i]] < 2) {
                    continue;
                }
                k++;
                c[a[i]]--;
                if (c[a[i]] == 0) {
                    c.erase(a[i]);
                }
                c[s - a[i]]--;
                if (c[s - a[i]] == 0) {
                    c.erase(s - a[i]);
                }
            }
        }
        answer = max(answer, k);
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
