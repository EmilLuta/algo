#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int answer = 1, c = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            c++;
        } else {
            c = 1;
        }
        answer = max(answer, c);
    }
    printf("%d\n", answer);
}
