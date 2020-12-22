#include <bits/stdc++.h>

using namespace std;

void mark(vector<vector<int>>& a, int r, int c, vector<pair<int, int>>& out) {
    a[r][c] = 1 - a[r][c];
    out.push_back({r + 1, c + 1});

}

void solve_three(vector<vector<int>>& a, int r, int c, vector<vector<pair<int, int>>>& out) {
    vector<pair<int, int>> temp;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (a[r + i][c + j] == 1) {
                mark(a, r + i, c + j, temp);
            }
        }
    }
    out.push_back(temp);
}

void solve_two(vector<vector<int>>& a, int r, int c, vector<vector<pair<int, int>>>& out) {
    vector<pair<int, int>> ones, zeros;
    vector<pair<int, int>> temp;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (a[r + i][c + j] == 1) {
                ones.push_back({r + i, c + j});
            } else {
                zeros.push_back({r + i, c + j});
            }
        }
    }
    assert(2 == zeros.size());
    for (int i = 0; i < (int)zeros.size(); i++) {
        mark(a, zeros[i].first, zeros[i].second, temp);
    }
    mark(a, ones[0].first, ones[0].second, temp);
    out.push_back(temp);
    solve_three(a, r, c, out);
}

void solve_one(vector<vector<int>>& a, int r, int c, vector<vector<pair<int, int>>>& out) {
    vector<pair<int, int>> ones, zeros;
    vector<pair<int, int>> temp;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (a[r + i][c + j] == 1) {
                ones.push_back({r + i, c + j});
            } else {
                zeros.push_back({r + i, c + j});
            }
        }
    }
    assert(3 == zeros.size());
    for (int i = 0; i < 2; i++) {
        mark(a, zeros[i].first, zeros[i].second, temp);
    }
    mark(a, ones[0].first, ones[0].second, temp);
    out.push_back(temp);
    solve_two(a, r, c, out);
}

void solve_four(vector<vector<int>>& a, int r, int c, vector<vector<pair<int, int>>>& out) {
    vector<pair<int, int>> temp;
    mark(a, r, c, temp);
    mark(a, r + 1, c, temp);
    mark(a, r, c + 1, temp);
    out.push_back(temp);
    solve_one(a, r, c, out);
}

void solve(int t) {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            a[i][j] = s[j] - '0';
        }
    }
    vector<vector<pair<int, int>>> out;
    for (int r = 0; r < n - 2; r++) {
        for (int c = 0; c < m - 2; c++) {
            if (a[r][c] == 1) {
                vector<pair<int, int>> temp;
                vector<pair<int, int>> nodes = {{r, c}, {r + 1, c}, {r, c + 1}};
                for (pair<int, int> p : nodes) {
                    mark(a, p.first, p.second, temp);
                }
                out.push_back(temp);
            }
        }
    }
    for (int r = 0; r < n - 2; r++) {
        if (a[r][m - 2] == 1 || a[r][m - 1] == 1) {
            vector<pair<int, int>> temp;
            int moves = 0;
            if (a[r][m - 2] == 1) {
                mark(a, r, m - 2, temp);
                moves++;
            }
            mark(a, r + 1, m - 2, temp);
            moves++;
            if (a[r][m - 1] == 1) {
                mark(a, r, m - 1, temp);
                moves++;
            }
            if (moves < 3) {
                mark(a, r + 1, m - 1, temp);
            }
            out.push_back(temp);
        }
    }
    for (int c = 0; c < m - 2; c++) {
        if (a[n - 2][c] == 1 || a[n - 1][c] == 1) {
            vector<pair<int, int>> temp;
            int moves = 0;
            if (a[n - 2][c] == 1) {
                mark(a, n - 2, c, temp);
                moves++;
            }
            mark(a, n - 2, c + 1, temp);
            moves++;
            if (a[n - 1][c] == 1) {
                mark(a, n - 1, c, temp);
                moves++;
            }
            if (moves < 3) {
                mark(a, n - 1, c + 1, temp);
            }
            out.push_back(temp);
        }
    }
    int s = 0;
    for (int r = n - 2; r < n; r++) {
        for (int c = m - 2; c < m; c++) {
            s += a[r][c];
        }
    }
    switch (s) {
        case 4:
            solve_four(a, n - 2, m - 2, out);
                break;
        case 3:
            solve_three(a, n - 2, m - 2, out);
            break;
        case 2:
            solve_two(a, n - 2, m - 2, out);
            break;
        case 1:
            solve_one(a, n - 2, m - 2, out);
            break;
        case 0:
            break;
        default:
            assert(false);
    }
    printf("%d\n", (int)out.size());
    for (vector<pair<int, int>>& v : out) {
        assert((int)v.size() == 3);
        for (pair<int, int>& p : v) {
            printf("%d %d ", p.first, p.second);
        }
        printf("\n");
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
