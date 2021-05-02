#include <bits/stdc++.h>

using namespace std;

void solve(int t) {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int answer = 0;
    for (int i = 0; i < n - 1; i++) {
        int j = i;
        while (a[j] != i + 1) {
            j++;
        }
        reverse(a.begin() + i, a.begin() + j + 1);
        answer += j - i + 1;
    }
    printf("Case #%d: %d\n", t, answer);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        solve(t);
    }
}
