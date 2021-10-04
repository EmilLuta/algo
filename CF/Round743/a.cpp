#include <bits/stdc++.h>

using namespace std;

void solve(int t) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int answer = 0;
    for (int i = 0; i < n; i++) {
        answer += s[i] - '0';
        if (i != n - 1 && s[i] != '0') {
            answer++;
        }
    }
    printf("%d\n", answer);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(t);
    }
}
