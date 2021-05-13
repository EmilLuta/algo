#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    int start = n * 4, so_far = 0;
    while (so_far < n) {
        printf("%d ", start);
        so_far++;
        start -= 2;
    }
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
