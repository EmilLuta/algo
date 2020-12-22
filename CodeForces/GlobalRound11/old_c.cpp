#include <bits/stdc++.h>

using namespace std;

int answer = 0;
int x = 0;
void solve(vector<vector<int>>& c, int t, int so_far, pair<int, int> pos) {
    printf("solving\n");
    x++;
    int n = c.size();
    for (int i = 0; i < n; i++) {
        if (t >= c[i][0]) {
            continue;
        }
        int dist = abs(pos.first - c[i][1]) + abs(pos.second - c[i][2]);
        if (dist + t <= c[i][0]) {
            solve(c, c[i][0], so_far + 1, {c[i][1], c[i][2]});
            answer = max(answer, so_far + 1);
        }
    }
}

int main() {
    int r, n;
    scanf("%d%d", &r, &n);
    vector<vector<int>> c(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &c[i][0], &c[i][1], &c[i][2]);
    }
    solve(c, 0, 0, {1, 1});
    printf("answer = %d, x = %d\n", answer, x);
}
