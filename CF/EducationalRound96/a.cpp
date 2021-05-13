#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    for (int three = 0; three <= n / 3; three++) {
        int so_far = three * 3;
        if (so_far == n) {
            printf("%d %d %d\n", three, 0, 0);
            return;
        }
        for (int five = 0; five <= (n - so_far) / 5; five++) {
            int so_far_with_five = so_far + five * 5;
            if (so_far_with_five == n) {
                printf("%d %d %d\n", three, five, 0);
                return;
            }
            int diff = n - so_far_with_five;
            if (diff % 7 == 0) {
                printf("%d %d %d\n", three, five, diff / 7);
                return;
            }
        }
    }
    printf("-1\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
