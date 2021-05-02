#include <bits/stdc++.h>

using namespace std;

void solve(int t) {
    int n;
    scanf("%d", &n);
    vector<int> miners, mines;
    for (int i = 0; i < 2 * n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (x == 0) {
            miners.push_back(abs(y));
        } else {
            mines.push_back(abs(x));
        }
    }
    sort(miners.begin(), miners.end());
    sort(mines.begin(), mines.end());
    long double answer = 0;
    for (int i = 0; i < n; i++) {
        answer += sqrt(1.0 * miners[i] * miners[i] + 1.0 * mines[i] * mines[i]);
    }
    printf("%.15Lf\n", answer);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int tc = 1; tc <= t; tc++) {
        solve(tc);
    }
}
