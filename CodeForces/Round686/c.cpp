#include <bits/stdc++.h>

using namespace std;

// ios::sync_with_stdio(0);
// cin.tie(0);

# define deb_v(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << a[i] << " "; \
    cerr << ")\n";

# define deb(x) cerr << #x << " = " << x << "\n";

void solve(int t) {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int start = 1, end = n - 1;
    while (start < n && a[start] == a[start - 1]) {
        start++;
    }
    while (end > 0 && a[end] == a[end - 1]) {
        end--;
    }
    if (start > end) {
        printf("0\n");
        return;
    }
    map<int, int> d;
    for (int i = start; i < end; i++) {
        int begin = i;
        while (i < end && a[i] == a[i + 1]) {
            i++;
        }
        d[a[begin]]++;
    }
    if (d[a[0]] == 0 || d[a[n - 1]] == 0) {
        printf("1\n");
        return;
    }
    int answer = INT_MAX;
    for (pair<int, int> p : d) {
        p.second++;
        answer = min(answer, p.second);
    }
    if (answer == INT_MAX) {
        printf("0\n");
    } else {
        printf("%d\n", answer);
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
