#include <bits/stdc++.h>

using namespace std;

# define deb_v(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << item << " "; \
    cerr << ")\n";

# define deb_v_p(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << "(" << item.first << ", " << item.second << ") "; \
    cerr << ")\n";

# define deb(x) cerr << #x << " = " << x << "\n";

void fix(vector<int>& row, vector<int>& col, int index, int& answer, set<int>& seen) {
    if (col[index] == -1) {
        answer += 1;
        col[row[index]] = -1;
        row[index] = -1;
        return;
    }
    if (seen.count(index) != 0) {
        answer += 1;
        /* printf("in seen\n"); */
        /* printf("attempting to change col at index %d\n", row[index]); */
        /* printf("attempting to change row at index %d\n", index); */
        col[row[index]] = -1;
        row[index] = -1;
        return;
    }
    seen.insert(index);
    fix(row, col, col[index], answer, seen);
    answer++;
    /* printf("outside\n"); */
    /* printf("attempting to change col at index %d\n", row[index]); */
    /* printf("attempting to change row at index %d\n", index); */
    if (row[index] != -1) {
        col[row[index]] = -1;
    }
    row[index] = -1;
}

void solve(int t) {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> row(n + 1, -1);
    vector<int> col(n + 1, -1);
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (y == x) {
            continue;
        }
        row[y] = x;
        col[x] = y;
    }
    int answer = 0;
    for (int i = 1; i <= n; i++) {
        if (row[i] != -1) {
            set<int> seen;
            fix(row, col, i, answer, seen);
        }
    }
    printf("%d\n", answer);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
