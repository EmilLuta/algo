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

bool is_hill(vector<int>& a, int i, int n) {
    return i > 0 && i < n - 1 && a[i - 1] < a[i] && a[i] > a[i + 1];
}

bool is_valley(vector<int>& a, int i, int n) {
    return i > 0 && i < n - 1 && a[i - 1] > a[i] && a[i] < a[i + 1];
}

void solve(int t) {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    vector<bool> added(n, false);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int answer = 0;
    for (int i = 1; i < n - 1; i++) {
        if (is_hill(a, i, n) || is_valley(a, i, n)) {
            answer++;
            added[i] = true;
        }
    }
    int all = answer;
    for (int i = 1; i < n - 1; i++) {
        int minimum = min(a[i - 1], a[i + 1]);
        int maximum = max(a[i - 1], a[i + 1]);
        int prev_a_i = a[i];
        for (int set_to : {minimum, maximum}) {
            int take_out = 0;
            a[i] = set_to;
            for (int change = -1; change <= 1; change++) {
                if (added[i + change]) {
                    if (!is_hill(a, i + change, n) && !is_valley(a, i + change, n)) {
                        take_out++;
                    }
                } else {
                    if (is_hill(a, i + change, n) || is_valley(a, i + change, n)) {
                        take_out--;
                    }
                }
            }
            answer = min(answer, all - take_out);
        }
        a[i] = prev_a_i;
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
