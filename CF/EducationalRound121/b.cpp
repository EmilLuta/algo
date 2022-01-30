#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int double_index = -1;
    for (int i = 0; i < n - 1; i++) {
        int val = s[i] - '0' + s[i + 1] - '0';
        if (val > 9) {
            double_index = i;
        }
    }
    string answer(s.begin(), s.end());
    if (double_index != -1) {
        int val = s[double_index] - '0' + s[double_index + 1] - '0';
        answer[double_index] = val / 10 + '0';
        answer[double_index + 1] = val % 10 + '0';
    } else {
        int val = s[0] - '0' + s[1] - '0';
        answer.erase(0, 1);
        answer[0] = val + '0';
    }
    cout << answer << endl;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
