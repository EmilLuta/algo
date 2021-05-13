#include <bits/stdc++.h>

using namespace std;


int main() {
    int r, n;
    scanf("%d%d", &r, &n);
    vector<vector<int>> c(n + 1, vector<int>(3));
    c[0] = {0, 1, 1};
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", &c[i][0], &c[i][1], &c[i][2]);
    }
    vector<vector<int>> dag(n + 1, vector<int>(0));
    for (int i = 0; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (c[i][0] + 1000 < c[j][0]) {
                break;
            }
            int cost = c[i][0] + abs(c[i][1] - c[j][1]) + abs(c[i][2] - c[j][2]);
            if (cost <= c[j][0]) {
                dag[i].push_back(j);
            }
        }
    }
    /* for (int i = 0; i <= n; i++) { */
    /*     printf("from %d can go to [", i); */
    /*     for (int j : dag[i]) { */
    /*         printf("%d, ", j); */
    /*     } */
    /*     printf("]\n"); */
    /* } */
    vector<int> parents(n + 1, 0);
    vector<int> costs(n + 1, 0);
    costs[0] = -1;
    vector<int> q;
    q.push_back(0);
    int index = 0;
    /* set<int> seen; */
    /* seen.insert(0); */
    while(index < (int)q.size()) {
        int i = q[index];
        index++;
        costs[i] = max(costs[i], costs[parents[i]] + 1);
        for (int j : dag[i]) {
            /* if (seen.count(j) != 0) { */
                /* continue; */
            /* } */
            q.push_back(j);
            parents[j] = i;
            /* seen.insert(j); */
        }
    }
    int answer = 0;
    for (int i = 1; i <= n; i++) {
        answer = max(answer, costs[i]);
    }
    printf("%d\n", answer);
}
