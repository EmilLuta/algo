#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    int ones = 0;
    vector<int> a(n);
    bool first_winning = true, mid = false;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if (x == 1) {
            if (!mid && i != n - 1) {
                first_winning = !first_winning;
            }
            mid = false;
        } else {
            mid = true;
        }
    }
    if (first_winning) {
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
