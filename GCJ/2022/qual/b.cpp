#include <bits/stdc++.h>

using namespace std;

void solve(int T) {
    vector<int> vals(4, 1e7);
    for (int i = 0; i < 3; i++) {
        vector<int> curr(4);
        for (int j = 0; j < 4; j++) {
            scanf("%d", &curr[j]);
            vals[j] = min(vals[j], curr[j]);
        }
    }
    printf("Case #%d: ", T);
    int left = 1e6;
    vector<int> out(4);
    for (int i = 0; i < 4; i++) {
        out[i] = min(left, vals[i]);
        left -= out[i];
    }
    if (left > 0) {
        printf("IMPOSSIBLE");
    } else {
        for (int i = 0; i < 4; i++) {
            printf("%d ", out[i]);
        }
    }
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
