#include<bits/stdc++.h>

using namespace std;


void go_rec(vector<vector<int>> &sums, int &total, int p, int n, int k, vector<int> picks, set<vector<int>> &visited) {
    visited.insert(picks);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += picks[i];
    }
    if (sum > p) {
        return;
    } else if (sum < p) {
        for (int i = 0; i < n; i++) {
            for (int opt: {-1, 1}) {
                if (picks[i] + opt >= 0 && picks[i] < k) {
                    picks[i] += opt;
                    if (visited.count(picks) == 0) {
                        go_rec(sums, total, p, n, k, picks, visited);
                    }
                    picks[i] -= opt;
                }
            }
        }
    } else {
        int curr = 0;
        for (int i = 0; i < n; i++) {
            /* printf("picks[i] = %d\n", picks[i]); */
            /* printf("curr is: %d, adding: %d from sums[%d][picks[%d]]; picks[i] = %d\n", curr, sums[i][picks[i]], i, i, picks[i]); */
            curr += sums[i][picks[i]];
        }
        /* for (int i = 0; i < n; i++) { */
        /*     printf("sums[%d] = ", i); */
        /*     for (int j = 0; j <= p; j++) { */
        /*         if (j == p) { */
        /*             printf("%d\n", sums[i][j]); */
        /*             continue; */
        /*         } */
        /*         printf("%d ", sums[i][j]); */
        /*     } */
        /* } */
        /* printf("Curr value=%d\n", curr); */
        total = max(total, curr);
    }
}

int main() {
    int t;
    scanf("%d", &t);
    int tc = 1;
    while (t > 0) {
        t--;
        int n, k, p;
        scanf("%d %d %d", &n, &k, &p);
        vector<vector<int>> stacks(n, vector<int>(k));
        vector<vector<int>> sums(n, vector<int>(k + 1, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                scanf("%d", &stacks[i][j]);
                sums[i][j + 1] = stacks[i][j] + sums[i][j];
            }
        }
        int total = 0;
        set<vector<int>> visited;
        vector<int> start = vector<int>(n, 0);
        go_rec(sums, total, p, n, k, start, visited);
        printf("Case #%d: %d\n", tc, total);
        tc++;
    }
}
