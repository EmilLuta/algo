#include <bits/stdc++.h>

using namespace std;

const int N = 500;

int pref[N + 1][N + 1];
char grid[N][N];
bool seen[N][N];
int cc[N][N];
int is_inside[N * N + 1];
int cc_size[N * N + 1];
int sum = 0;
int k;
int n;

void insert(int r, int c) {
    if (grid[r][c] == '.') {
        int id = cc[r][c];
        is_inside[id]++;
        if (is_inside[id] == 1) {
            sum += cc_size[id];
        }
    }
}

void erase(int r, int c) {
    if (grid[r][c] == '.') {
        int id = cc[r][c];
        is_inside[id]--;
        if (is_inside[id] == 0) {
            sum -= cc_size[id];
        }
    }
}

bool inside(int r, int c) {
    return 0 <= r && r < n && 0 <= c && c < n;
}

void fix_border(int rl, int cl) {
    vector<pair<int, int>> to_add, to_remove;
    int rh = rl + k;
    int ch = cl + k;
    if (rl > 0) {
        to_add.push_back({rl - 1, ch - 1});
        if (cl >= 1) {
            to_remove.push_back({rl - 1, cl - 1});
        }
    }
    if (rh < n) {
        to_add.push_back({rh, ch - 1});
        if (cl >= 1) {
            to_remove.push_back({rh, cl - 1});
        }
    }
    for (int r = rl; r < rh; r++) {
        if (ch < n) {
            to_add.push_back({r, ch});
        }
        if (cl >= 2) {
            to_remove.push_back({r, cl - 2});
        }
    }
    for (pair<int, int> add : to_add) {
        insert(add.first, add.second);
    }
    for (pair<int, int> remove: to_remove) {
        erase(remove.first, remove.second);
    }
}

void init_border(int rl) {
    int rh = rl + k;
    vector<pair<int, int>> to_add;
    for (int c = 0; c < k; c++) {
        if (rl > 0) {
            to_add.push_back({rl - 1, c});
        }
        if (rh < n) {
            to_add.push_back({rh, c});
        }
    }
    if (k < n) {
        for (int r = rl; r < rh; r++) {
            to_add.push_back({r, k});
        }
    }
    for (pair<int, int> add : to_add) {
        insert(add.first, add.second);
    }

}

void init(int R) {
    for (int r = 0; r < k; r++) {
        for (int c = 0; c < k; c++) {
            insert(R + r, c);
        }
    }
    init_border(R);
}

int val_for_char(char c) {
    return c == '.' ? 0 : 1;
}

bool valid(int r, int c) {
    return 0 <= r && r < n && 0 <= c && c < n;
}

void dfs(int r, int c, int id, int& so_far) {
    seen[r][c] = true;
    cc[r][c] = id;
    so_far++;
    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    for (pair<int, int> d : dirs) {
        int n_r = r + d.first;
        int n_c = c + d.second;
        if (valid(n_r, n_c) && !seen[n_r][n_c] && grid[n_r][n_c] == '.') {
            dfs(n_r, n_c, id, so_far);
        }
    }
}

int query(int r, int c) {
    return pref[r + k][c + k] - pref[r + k][c] - pref[r][c + k] + pref[r][c];
}

void clean_up(int R) {
    for (int r = 0; r < k; r++) {
        for (int c = n - k; c < n; c++) {
            erase(R + r, c);
        }
    }
    if (k < n) {
        for (int r = 0; r < k; r++) {
            erase(R + r, n - k - 1);
        }
    }
    for (int c = n - k; c < n; c++) {
        if (R > 0) {
            erase(R - 1, c);
        }
        if (R + k < n) {
            erase(R + k, c);
        }
    }
}

int solve() {
    pref[1][1] = val_for_char(grid[0][0]);
    for (int r = 1; r <= n; r++) {
        for (int c = 1; c <= n; c++) {
            pref[r][c] = pref[r - 1][c] + pref[r][c - 1] - pref[r - 1][c - 1] + val_for_char(grid[r - 1][c - 1]);
        }
    }
    int global_id = 1;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            int val = 0;
            if (grid[r][c] == '.' && !seen[r][c]) {
                dfs(r, c, global_id, val);
                cc_size[global_id] = val;
                global_id++;
            }
        }
    }
    int answer = 0;
    for (int R = 0; R <= n - k; R++) {
        init(R);
        answer = max(answer, sum + query(R, 0));
        for (int c = 1; c <= n - k; c++) {
            fix_border(R, c);
            answer = max(answer, sum + query(R, c));
        }
        clean_up(R);
    }
    return answer;
}

int main() {
    scanf("%d%d", &n, &k);
    for (int r = 0; r < n; r++) {
        string s;
        cin >> s;
        for (int c = 0; c < n ; c++) {
            grid[r][c] = s[c];
        }
    }
    printf("%d\n", solve());
}
