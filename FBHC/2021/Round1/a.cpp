#include <bits/stdc++.h>

using namespace std;

void solve(int t) {
    int l;
    cin >> l;
    string s;
    cin >> s;
    string new_s = "";
    for (int i = 0; i < l; i++) {
        if (s[i] != 'F') {
            new_s += s[i];
        }
    }
    int n = new_s.size();
    if (n == 0) {
        printf("Case #%d: 0\n", t);
        return;
    }
    bool is_o = new_s[0] == 'O' ? true : false;
    int answer = 0;
    for (int i = 1; i < n; i++) {
        if (new_s[i] == 'O') {
            if (is_o) {
                continue;
            } else {
                is_o = !is_o;
                answer++;
            }
        } else {
            if (!is_o) {
                continue;
            } else {
                is_o = !is_o;
                answer++;
            }
        }
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
