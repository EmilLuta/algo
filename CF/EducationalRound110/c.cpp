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
    string s;
    cin >> s;
    int n = s.size();
    int all_q = true;
    for (int i = 0; i < n; i++) {
        if (s[i] != '?') {
            all_q = false;
        }
    }
    if (all_q) {
        printf("%d\n", n * (n + 1) / 2);
        return;
    }
    if (s[0] == '?') {
        int i = 0;
        while (s[i] == '?') {
            i++;
        }
        for (int j = i - 1; j >= 0; j--) {
            s[j] = s[j + 1] == '1' ? '0' : '1';
        }
    }
    if (s[n - 1] == '?') {
        int i = 0;
        while (s[i] == '?') {
            i--;
        }
        for (int j = i + 1; j < n; j++) {
            s[j] = s[j - 1] == '1' ? '0' : '1';
        }
    }
    int i = 1;
    while (i < n) {
        if (s[i] == '?') {
            int start = i;
            while (s[i] == '?') {
                i++;
            }
        }
        i++;
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
