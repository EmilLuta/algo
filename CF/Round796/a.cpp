#include <bits/stdc++.h>

using namespace std;

void solve() {
    int x;
    scanf("%d", &x);
    int a = x;
    int y = 0;
    int p_2 = 1;
    while (a != 0) {
        if (a % 2 == 1) {
            y = p_2;
            break;
        }
        p_2 *= 2;
        a /= 2;
    }
    if (x <= y) {
        if (x % 2 == 1) {
            y += 2;
        } else {
            y += 1;
        }
    }
    printf("%d\n", y);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
