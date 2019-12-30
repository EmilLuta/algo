#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        int n, m;
        scanf("%d %d", &n, &m);
        vector<int> fridges(n);
        for (int i = 0; i < n ; i++) {
            scanf("%d", &fridges[i]);
        }
        if (m < n || n == 2) {
            printf("-1\n");
            continue;
        }
        int sum = 0;
        vector<pair<int, int>> output(n);
        for (int i = 0; i < n; i++) {
            sum += fridges[i];
            int a = i + 1;
            int b = a % n + 1;
            output[i] = {a, b};
        }
        printf("%d\n", sum * 2);
        for (int i = 0; i < n; i++) {
            printf("%d %d\n", output[i].first, output[i].second);
        }
    }
}
