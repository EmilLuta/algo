#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    map<int, int> counter = {{0, 1}};
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            x++;
        } else {
            y++;
        }
        counter[y - x]++;
    }
    int answer = 0;
    for (auto p : counter) {
        answer += p.second * (p.second - 1) / 2;
    }
}
