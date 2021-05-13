#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    char p = ' ';
    int answer = 0, ones = 0, zeros = 0, curr_o = 0, curr_z = 0;
    for (int i = 0; i < n; i++) {
        char c;
        scanf(" %c", &c);
        if (c == p) {
            if (c == '1') {
                curr_o++;
            } else {
                curr_z++;
            }
        } else {
            ones += max(0, curr_o);
            zeros += max(0, curr_z);
            curr_o = 0;
            curr_z = 0;
        }
        p = c;
    }
    printf("%d\n", max(ones, zeros));
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
