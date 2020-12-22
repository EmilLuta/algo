#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    int s = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        s += a[i];
    }
    if (s % n != 0) {
        printf("-1\n");
        return;
    }
    int avg = s / n;
    vector<vector<int>> answer;
    for (int i = 1; i < n; i++) {
        int mod = a[i] % (i + 1);
        if (mod != 0) {
            int diff = (i + 1) - mod;
            answer.push_back({1, i + 1, diff});
            a[0] -= diff;
            a[i] += diff;
        }
        int x = a[i] / (i + 1);
        answer.push_back({i + 1, 1, x});
        int delta = x * (i + 1);
        a[i] -= delta;
        a[0] += delta;
    }
    for (int i = 1; i < n; i++) {
        answer.push_back({1, i + 1, avg});
        a[i] += avg;
        a[0] -= avg;
    }
    printf("%d\n", answer.size());
    for (auto x: answer) {
        printf("%d %d %d\n", x[0], x[1], x[2]);
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
