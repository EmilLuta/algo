#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    int answer = 1, current = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            current++;
        } else {
            current = 1;
        }
        answer = max(answer, current);
    }
    printf("%d\n", answer);
}
