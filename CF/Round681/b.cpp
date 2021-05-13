#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b;
    scanf("%d%d", &a, &b);
    string s;
    cin >> s;
    int n = s.size();
    int gap = 0;
    int i = 0;
    vector<pair<int, int>> ones;
    while (i < n) {
        if (s[i] == '1') {
            int start = i;
            while (i < n && s[i] == '1') {
                i++;
            }
            int end = i;
            ones.push_back({start, end - 1});
        }
        i++;
    }
    int m = ones.size();
    if (m == 0) {
        printf("0\n");
        return;
    }
    int answer = a;
    for (int j = 1; j < (int)ones.size(); j++) {
        answer += min(b * (ones[j].first - ones[j - 1].second - 1), a);
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
