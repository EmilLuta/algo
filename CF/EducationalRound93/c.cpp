#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    string s;
    cin >> s;
    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + (s[i - 1] - '0');
    }
    /* printf("pref = ["); */
    /* for (int i = 0; i < n + 1; i++) { */
        /* printf("%d, ", pref[i]); */
    /* } */
    /* printf("]\n"); */
    int answer = 0;
    for (int size = 0; size < n; size++) {
        for (int i = 0; i < n - size; i++) {
            /* printf("verifying range %d - %d\n", i, i + size + 1); */
            if (pref[i + size + 1] - pref[i] == size + 1) {
                /* printf("added\n"); */
                answer++;
            }
        }
    }
    printf("%d\n", answer);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
