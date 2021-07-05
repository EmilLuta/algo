#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, x;
    scanf("%d%d", &n, &x);
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }
    map<int, int> curr;
    map<int, int> prev;
    for (int coin : c) {
        prev[coin] = 1;
    }
    while (true) {
        for (int coin : c) {
            for (pair<int, int> p : prev) {
                int val = p.first;
                int count = p.second;
                if (val == x) {
                    curr[val] += count;
                    continue;
                }
                if (val + coin > x) {
                    continue;
                }
                curr[val + coin] += count;
                curr[val + coin] %= MOD;
            }
        }
        prev = curr;
        curr.clear();
        if (prev.size() == 0) {
            break;
        }
        if (prev.size() == 1 && prev.count(x) > 0) {
            break;
        }
        for (int i = 0; i <= x; i++) {
            if (prev.count(i)) {
                printf("%d ", prev[i]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
    for (int i = 0; i <= x; i++) {
        printf("%d ", prev[x]);
    }
    printf("\n");
    printf("%d\n", prev[x]);
}
