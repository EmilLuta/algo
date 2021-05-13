#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    string s;
    cin >> s;
    string new_s;
    new_s.push_back(s[0]);
    int skips = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) {
            skips++;
        }
        new_s.push_back(s[i]);
    }
    map<int, vector<pair<int, int>>> gaps;
    int start = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) {
            int size = i - start;
            if (size > 1) {
                gaps[size].push_back({start, i - 1});
            }
            start = i;
        }
    }
    int skips = 0;
    start = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) {
            skips++;
            start = i;
        } else {
            start
        }
    }
    for (auto k_v : gaps) {
        printf("for gap = %d, [", k_v.first);
        for (auto x : k_v.second) {
            printf("{%d, %d}, ", x.first, x.second);
        }
        printf("]\n");
    }
    s = new_s;
    int start = 0;
    int end = n;
    int moves = 0;
    while (start < end) {
        int index = start + 1;
        while (index < end && s[index] == s[index - 1]) {
            index++;
        }
        if (start + 1 == index) {
            end--;
            start++;
        } else {
            start = index;
        }
        /* printf("start = %d, end = %d\n", start, end); */
        moves++;
    }
    printf("%d\n", moves);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
