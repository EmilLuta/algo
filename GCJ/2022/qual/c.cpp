#include <bits/stdc++.h>

using namespace std;

void solve(int t) {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a.begin(), a.end());
    int answer = 0;
    int min_val = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] < min_val) {
            continue;
        }
        min_val++;
        answer++;
    }
    printf("Case #%d: %d\n", t, answer);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
