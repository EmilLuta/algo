#include <bits/stdc++.h>

using namespace std;

int dist(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void solve() {
    pair<int, int> A = {0, 0};
    pair<int, int> B;
    scanf("%d%d", &B.first, &B.second);
    int d_AB = dist(A, B);
    if (d_AB % 2 == 1) {
        printf("-1 -1\n");
        return;
    }
    int half_d_AB = d_AB / 2;
    for (int xx = 0; xx <= 50; xx++) {
        for (int yy = 0; yy <= 50; yy++) {
            pair<int, int> C = {xx, yy};
            int d_AC = dist(A, C);
            int d_BC = dist(B, C);
            if (d_BC == half_d_AB && d_AC == half_d_AB) {
                printf("%d %d\n", xx, yy);
                return;
            }
        }
    }
    printf("-1 -1\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        solve();
        t--;
    }
}
