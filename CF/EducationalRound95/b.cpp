#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    vector<int> a(n), state(n), u;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &state[i]);
        if (state[i] == 0) {
            u.push_back(a[i]);
        }
    }
    sort(u.begin(), u.end());
    reverse(u.begin(), u.end());
    int index = 0;
    for (int i = 0; i < n; i++) {
        if (state[i] == 0) {
            a[i] = u[index];
            index++;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
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
