#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    vector<int> x(n, 0);
    x[0] = a;
    x[n / 2] = b;
    set<int> taken = {a, b};
    int curr_left = n;
    int i_left = 1;
    while (i_left < n / 2) {
        if (curr_left <= a) {
            printf("-1\n");
            return;
        }
        if (taken.count(curr_left) != 0) {
            curr_left--;
            continue;
        }
        x[i_left] = curr_left;
        taken.insert(curr_left);
        i_left++;
        curr_left--;
    }
    int curr_right = 1;
    int i_right = n / 2 + 1;
    while (i_right < n) {
        if (curr_right >= b) {
            printf("-1\n");
            return;
        }
        if (taken.count(curr_right) != 0) {
            curr_right++;
            continue;
        }
        x[i_right] = curr_right;
        i_right++;
        curr_right++;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        solve();
        t--;
    }
}
