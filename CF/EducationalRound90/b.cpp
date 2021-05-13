#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int moves = 0, ones = 0, zeros = 0;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            ones++;
        } else {
            zeros++;
        }
    }
    moves = min(ones, zeros);
    if (moves % 2 == 1) {
        printf("DA\n");
    } else {
        printf("NET\n");
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
