#include <bits/stdc++.h>

using namespace std;

void print_counter(vector<vector<int>>& c) {
    int n = c.size();
    for (int i = 1; i < n; i++) {
        printf("c[%d] = (", i);
        for (int j = 0; j < (int)c[i].size(); j++) {
            printf("%d ", c[i][j]);
        }
        printf(")\n");
    }
    printf("\n");
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<vector<int>> a(m);
    vector<vector<int>> c(n + 1);
    for (int i = 0; i < m; i++) {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            int x;
            scanf("%d", &x);
            a[i].push_back(x);
        }
        reverse(a[i].begin(), a[i].end());
        c[a[i][k - 1]].push_back(i);
    }
    vector<int> q;
    for (int i = 1; i <= n; i++) {
        if (c[i].size() == 2) {
            q.push_back(i);
        }
    }
    int index = 0;
    int counter = 0;
    /* print_counter(c); */
    while (index < (int)q.size()) {
        int x = q[index];
        index++;
        counter++;
        int buck_one = c[x][0];
        a[buck_one].pop_back();
        if (a[buck_one].size() != 0) {
            int buck_one_no = a[buck_one][a[buck_one].size() - 1];
            c[buck_one_no].push_back(buck_one);
            if (c[buck_one_no].size() == 2) {
                q.push_back(buck_one_no);
            }
        }

        int buck_two = c[x][1];
        a[buck_two].pop_back();
        if (a[buck_two].size() != 0) {
            int buck_two_no = a[buck_two][a[buck_two].size() - 1];
            c[buck_two_no].push_back(buck_two);
            if (c[buck_two_no].size() == 2) {
                q.push_back(buck_two_no);
            }
        }
        c[x] = {};
        /* print_counter(c); */
    }
    if (counter == n) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
}
