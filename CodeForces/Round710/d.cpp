#include <bits/stdc++.h>

using namespace std;

// ios::sync_with_stdio(0);
// cin.tie(0);

# define deb_v(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << item << " "; \
    cerr << ")\n";

# define deb(x) cerr << #x << " = " << x << "\n";

# define deb_v_p(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << "(" << item.first << ", " << item.second << ") "; \
    cerr << ")\n";

void solve(int t) {
    int n;
    scanf("%d", &n);
    map<int, int> counter;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        counter[x]++;
    }
    int m = 0;
    int d = -1;
    int answer = 0;
    if (n % 2 == 1) {
        answer++;
        for (pair<int, int> p : counter) {
            if (p.second > m) {
                d = p.first;
                m = p.second;
            }
        }
        counter[d]--;
        n--;
    }
    for (pair<int, int> p : counter) {
        if (p.second == n) {
            answer += n;
        }
        else if (p.second > n / 2) {
            answer += 2 * p.second - n;
        }
    }
    printf("%d\n", answer);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
