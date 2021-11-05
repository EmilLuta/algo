#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long a, b, c;
    scanf("%lld%lld%lld", &a, &b, &c);
    if (c % 2 == 1) {
        if (b % 2 == 1) {
            if (a % 2 == 1) {
                printf("0\n");
                return;
            } else {
                printf("1\n");
                return;
            }
        } else {
            if (a % 2 == 1) {
                printf("0\n");
                return;
            } else {
                printf("1\n");
                return;
            }
        }
    } else {
        if (b % 2 == 1) {
            if (a % 2 == 1) {
                printf("1\n");
                return;
            } else {
                printf("0\n");
                return;
            }
        } else {
            if (a % 2 == 1) {
                printf("1\n");
                return;
            } else {
                printf("0\n");
                return;
            }
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        solve();
        t--;
    }
}
