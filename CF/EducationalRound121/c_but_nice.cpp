#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    vector<int> k(n), h(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &k[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]);
    }
    vector<pair<int, int>> ranges(n);
    for (int i = 0; i < n; i++) {
        ranges[i].first = k[i] - h[i];
        ranges[i].second = k[i];
    }
    sort(ranges.begin(), ranges.end());
    long long answer = 0;
    int left = -1, right = -1;
    for (int i = 0; i < n; i++) {
        if (ranges[i].first >= right) {
            long long x = right - left;
            answer += x * (x + 1) / 2;
            left = ranges[i].first;
            right = ranges[i].second;
        } else {
            right = max(right, ranges[i].second);
        }
    }
    long long x = right - left;
    answer += x * (x + 1) / 2;
    printf("%lld\n", answer);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
