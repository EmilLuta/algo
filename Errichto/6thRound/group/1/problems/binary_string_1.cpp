#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    map<int, int> counter = {{0, 1}};
    int diff = 0;
    int answer = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            diff--;
        } else {
            diff++;
        }
        answer += counter[diff];
        counter[diff]++;
    }
    printf("%d\n", answer);
}
