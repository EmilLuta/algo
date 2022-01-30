#include <bits/stdc++.h>

using namespace std;

const int MAX = 500;

int comp[MAX][MAX];
bool seen[MAX][MAX];
int counter[MAX * 2 + 1];
int pref[MAX + 1][MAX + 1];

void print_comp() {
    printf("comp = [\n");
    for (int r = 0; r < 9; r++) {
        printf("\t");
        for (int c = 0; c < 9; c++) {
            printf("%d ", comp[r][c]);
        }
        printf("\n");
    }
    printf("]\n");
}

void print_counter() {
    printf("counter = [");
    for (int i = 0; i < 20; i++) {
        printf("%d ", counter[i]);
    }
    printf("]\n");
}

int val_for_char(char c) {
    return c == '.' ? 0 : 1;
}

int query(int r, int c, int k) {
    return pref[r + k][c + k] - pref[r + k][c] - pref[r][c + k] + pref[r][c];
}

bool valid(int r, int c, int n) {
    return 0 <= r && r < n && 0 <= c && c < n;
}

void dfs(vector<string>& grid, int r, int c, int id, int& so_far) {
    seen[r][c] = true;
    comp[r][c] = id;
    so_far++;
    int n = grid.size();
    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    for (pair<int, int> d : dirs) {
        int n_r = r + d.first;
        int n_c = c + d.second;
        if (valid(n_r, n_c, n) && !seen[n_r][n_c] && grid[n_r][n_c] == '.') {
            dfs(grid, n_r, n_c, id, so_far);
        }
    }
}

int update(int r, int c, set<int>& been_added) {
    int id = comp[r][c];
    int val = 0;
    if (been_added.count(id) == 0) {
        val = counter[id];
    }
    been_added.insert(id);
    /* if (val != 0) { */
    /*     printf("found I can add %d for comp %d (%d, %d)\n", val, id, r, c); */
    /* } */
    return val;
}

int solve(vector<string>& grid, int n, int k) {
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
                /* printf("%d %d\n", r, c); */
                dfs(grid, r, c, global_id, val);
                counter[global_id] = val;
                global_id++;
            }
        }
    }
    print_comp();
    print_counter();
    int answer = 0;
    for (int r = 0; r <= n - k; r++) {
        for (int c = 0; c <= n - k; c++) {
            int curr = query(r, c, k);
            printf("curr on query = %d\n", curr);
            set<int> been_added;
            vector<int> new_cs = {c, c + k - 1};
            if (c > 0) {
                new_cs.push_back(c - 1);
            }
            if (c + k < n) {
                new_cs.push_back(c + k);
            }
            /* printf("new_cs = ["); */
            /* for (int x : new_cs) { */
            /*     printf("%d ", x); */
            /* } */
            /* printf("]\n"); */
            for (int e_r = r; e_r < r + k; e_r++) {
                for (int new_c : new_cs) {
                    if (grid[e_r][new_c] == '.') {
                        int x = update(e_r, new_c, been_added);
                        printf("adding %d\n", x);
                        /* curr += update(e_r, new_c, been_added); */
                        curr += x;
                    }
                }
            }
            vector<int> new_rs = {r, r + k - 1};
            if (r > 0) {
                new_rs.push_back(r - 1);
            }
            if (r + k < n) {
                new_rs.push_back(r + k);
            }
            /* printf("new_rs = ["); */
            /* for (int x : new_rs) { */
            /*     printf("%d ", x); */
            /* } */
            /* printf("]\n"); */
            for (int e_c = c; e_c < c + k; e_c++) {
                for (int new_r : new_rs) {
                    int x = update(new_r, e_c, been_added);
                    printf("adding %d\n", x);
                    curr += x;
                    /* curr += update(new_r, e_c, been_added); */
                }
            }
            printf("for (r, c) = (%d, %d), k = %d, found answer = %d\n", r, c, k, curr);
            answer = max(answer, curr);
        }
    }
    return answer;
}

bool ok(int r, int c, int rl, int rh, int cl, int ch, int n, vector<string>& grid) {
    return (rl <= r && r < rh && cl <= c && c < ch) || (0 <= r && r < n && 0 <= c && c < n && grid[r][c] == '.');
}

void lol_dfs(vector<string>& grid, int n, int r, int c, int rl, int rh, int cl, int ch, int& so_far, set<pair<int, int>>& visited) {
    if (ok(r, c, rl, rh, cl, ch, n, grid) && visited.count({r, c}) == 0) {
        so_far++;
        visited.insert({r, c});
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (pair<int, int> d : dirs) {
            int nr = r + d.first;
            int nc = c + d.second;
            lol_dfs(grid, n, nr, nc, rl, rh, cl, ch, so_far, visited);
        }
    }
}

int brute_force(vector<string>& grid, int n, int k) {
    int answer = 0;
    for (int rl = 0; rl <= n - k; rl++) {
        for (int cl = 0; cl <= n - k; cl++) {
            int rh = rl + k;
            int ch = cl + k;
            int curr = 0;
            set<pair<int, int>> visited;
            lol_dfs(grid, n, rl, cl, rl, rh, cl, ch, curr, visited);
            /* for (int r = rl; r < rh; r++) { */
            /*     printf("r: %d -- ", r); */
            /*     for (int c = cl; c < ch; c++) { */
            /*         printf("%d ", c); */
            /*     } */
            /*     printf("\n"); */
            /* } */
            /* printf("\n"); */
            /* if (curr > answer) { */
            printf("found candidate with val = %d, starting at (%d %d)\n", curr, rl, cl);
            /* } */
            answer = max(answer, curr);
        }
    }
    return answer;
}

int main() {
    /* int n, k; */
    /* scanf("%d%d", &n, &k); */
    /* vector<string> grid(n); */
    /* for (int i = 0; i < n; i++) { */
    /*     cin >> grid[i]; */
    /* } */
    int n = rand() % 25 + 1;
    int k = rand() % (n - 1) + 1;
    cout << n << " " << k << endl;
    vector<string> grid(n);
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            int x = rand() % 3;
            grid[r][c] = x <= 1 ? 'x' : '.';
            printf("%c", grid[r][c]);
        }
        cout << "\n";
    }
    for (int i = 0; i < n; i++) {
        cout << grid[i] << endl;
    }
    printf("Mine: %d\n", solve(grid, n, k));
    printf("Brute Force: %d\n", brute_force(grid, n, k));
}
