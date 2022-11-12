#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> count(26);
    int answer = 0;
    for (int i = 0; i < n; i++) {
        int char_i = s[i] - 'a';
        if (count[char_i] > 0) {
            for (int j = 0; j < 26; j++) {
                answer += count[j];
                count[j] = 0;
            }
            answer -= 1;
            continue;
        }
        count[char_i]++;
    }
    for (int i = 0; i < 26; i++) {
        answer += count[i];
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
