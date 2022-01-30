#include <bits/stdc++.h>

using namespace std;

const int MAX = 150001;

void solve() {
    int n;
    scanf("%d", &n);
    vector<vector<int>> counter(MAX);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        counter[x].push_back(i);
    }
    int answer = -1;
    for (int i = 0; i < MAX; i++) {
        int x = counter[i].size();
        if (x > 1) {
            sort(counter[i].begin(), counter[i].end());
            for (int c = 0; c < x - 1; c++) {
                answer = max(answer, counter[i][c] + n - counter[i][c + 1]);
            }
        }
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
