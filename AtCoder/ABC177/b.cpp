#include <bits/stdc++.h>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    int answer = INT_MAX;
    for (int i = 0; i <= n - m; i++) {
        int now = 0;
        for (int j = 0; j < m; j++) {
            if (s[i + j] != t[j]) {
                now++;
            }
        }
        /* printf("now = %d\n", now); */
        answer = min(answer, now);
    }
    printf("%d\n", answer);
}
