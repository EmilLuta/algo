#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<string> a;
vector<vector<bool>> seen;
vector<vector<pair<int, int>>> from;
vector<vector<char>> dir;

bool valid(int r, int c) {
    return 0 <= r && r < n && 0 <= c && c < m;
}

struct Direction {
    int r;
    int c;
    char dir;
};

int main() {
    scanf("%d%d", &n, &m);
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    seen.resize(n, vector<bool>(m, false));
    from.resize(n, vector<pair<int, int>>(m));
    dir.resize(n, vector<char>(m));
    int start_r, start_c;
    int end_r, end_c;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (a[r][c] == 'A') {
                start_r = r;
                start_c = c;
            }
            if (a[r][c] == 'B') {
                end_r = r;
                end_c = c;
            }
        }
    }
    vector<pair<int, int>> q = {{start_r, start_c}};
    int index = 0;
    vector<Direction> dirs = {
        Direction{0, -1, 'L'},
        Direction{0, 1, 'R'},
        Direction{-1, 0, 'U'},
        Direction{1, 0, 'D'}
    };
    bool found = false;
    while (!found && index < (int)q.size()) {
        pair<int, int> p = q[index];
        index++;
        seen[p.first][p.second] = true;
        for (Direction d : dirs) {
            int r = p.first + d.r;
            int c = p.second + d.c;
            if (valid(r, c) && !seen[r][c]) {
                if (a[r][c] == '.') {
                    from[r][c] = p;
                    dir[r][c] = d.dir;
                    q.push_back({r, c});
                    seen[r][c] = true;
                }
                if (a[r][c] == 'B') {
                    from[r][c] = p;
                    dir[r][c] = d.dir;
                    seen[r][c] = true;
                    found = true;
                }
            }
        }
    }
    if (found) {
        int r = end_r, c = end_c;
        string out = "";
        int len = 0;
        while (r != start_r || c != start_c) {
            out += dir[r][c];
            pair<int, int> p = from[r][c];
            r = p.first;
            c = p.second;
            len++;
        }
        reverse(out.begin(), out.end());
        printf("YES\n");
        printf("%d\n", len);
        cout << out << endl;
        return 0;
    }
    printf("NO\n");
}
