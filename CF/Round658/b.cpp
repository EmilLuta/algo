#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    int ones = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int i = 0;
    while (a[i] == 1 && i < n) {
        ones++;
        i++;
    }
    if (i == n) {
        if (i % 2 == 1) {
            printf("First\n");
        } else {
            printf("Second\n");
        }
        return;
    }
    if (i % 2 == 0) {
        printf("First\n");
    } else {
        printf("Second\n");
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
