#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    int answer = 0;
    int rounds = (n + m - 1) / 2;
    set<vector<int>> prev, current;
    vector<int> vals(2);
    for (int i = 0; i < rounds; i++) {
        if (i == 0) {
            current.insert({0, 0, +1});
            current.insert({n - 1, m - 1, -1});
            vals[matrix[0][0]]++;
            vals[matrix[n - 1][m - 1]]++;
        } else {
            for (vector<int> p : prev) {
                vector<vector<int>> new_pairs = {{p[0] + p[2], p[1], p[2]}, {p[0], p[1] + p[2], p[2]}};
                for (vector<int> new_pair : new_pairs) {
                    if (0 <= new_pair[0] && new_pair[0] < n && 0 <= new_pair[1] && new_pair[1] < m) {
                        if (current.count(new_pair) == 0) {
                            current.insert(new_pair);
                            vals[matrix[new_pair[0]][new_pair[1]]]++;
                        }
                    }
                }
            }
        }
        /* printf("scanned %d positions; got 0s = %d and 1s = %d\n", current.size(), vals[0], vals[1]); */
        answer += min(vals[0], vals[1]);
        vals[0] = 0;
        vals[1] = 0;
        prev = current;
        current.clear();
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
