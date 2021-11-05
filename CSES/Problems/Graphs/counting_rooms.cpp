#include <bits/stdc++.h>

using namespace std;

vector<string> a;
vector<vector<bool>> seen;
int n;
int m;

bool valid(int r, int c) {
    return 0 <= r && r < n && 0 <= c && c < m;
}

void explore(int r, int c) {
    seen[r][c] = true;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if ((i != 0 && j != 0) || (i == 0 && j == 0)) {
                continue;
            }
            int rr = r + i;
            int cc = c + j;
            if (valid(rr, cc) && a[rr][cc] == '.' && !seen[rr][cc]) {
                explore(rr, cc);
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    a.resize(n);
    seen.resize(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int answer = 0;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (a[r][c] == '.' && !seen[r][c]) {
                explore(r, c);
                answer++;
            }
        }
    }
    printf("%d\n", answer);
}
