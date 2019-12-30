#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        int n;
        scanf("%d", &n);
        vector<int> q(n);
        vector<int> output(n);
        int current = 1;
        bool impossible = false;
        set<int> covered;
        for (int i = 0; i < n; i++) {
            scanf("%d", &q[i]);
        }

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                output[i] = q[i];
                covered.insert(q[i]);
                continue;
            }
            if (q[i] > q[i - 1]) {
                output[i] = q[i];
                covered.insert(q[i]);
                continue;
            }
            while (current < q[i] && covered.count(current) == 1) {
                current++;
            }
            if (current >= q[i]) {
                impossible = true;
                break;
            }
            output[i] = current;
            covered.insert(current);
        }
        if (impossible) {
            printf("-1\n");
            continue;
        }
        for (int i = 0; i < n; i++) {
            printf("%d ", output[i]);
        }
        printf("\n");
    }
}
