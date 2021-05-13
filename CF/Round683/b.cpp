#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    int neg = 0;
    int zero = 0;
    int smallest = INT_MAX;
    int answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            scanf("%d", &x);
            if (x < 0) {
                neg++;
            }
            if (x == 0) {
                zero++;
            }
            answer += abs(x);
            if (x != 0) {
                smallest = min(smallest, abs(x));
            }
        }
    }
    if (zero != 0 || neg % 2 == 0) {
        printf("%d\n", answer);
        return;
    }
    printf("%d\n", answer - 2 * smallest);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
