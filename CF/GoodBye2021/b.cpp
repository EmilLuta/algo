#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    string s;
    cin >> s;
    if (n > 1 && s[0] == s[1]) {
        printf("%c%c\n", s[0], s[0]);
        return;
    }
    int i = 1;
    char prev = s[0];
    while (i < n && s[i] <= prev) {
        prev = s[i];
        i++;
    }
    for (int j = 0; j < i; j++) {
        printf("%c", s[j]);
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", s[j]);
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
