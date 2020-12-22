#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    set<int> avail;
    for (int i = 1; i <= 400; i++) {
        avail.insert(i);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a.begin(), a.end());
    int answer = 0;
    for (int i = 0; i < n; i++) {
        auto x = avail.lower_bound(a[i]);
        int low, high;
        if (x != avail.end()) {
            high = *x;
        } else {
            high = 404;
        }
        if (x != avail.begin()) {
            low = *(--x);
        } else {
            low = -404;
        }
        int down = abs(low - a[i]);
        int up = abs(high - a[i]);
        if (up >= down) {
            answer += down;
            avail.erase(low);
        } else {
            answer += up;
            avail.erase(high);
        }
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
