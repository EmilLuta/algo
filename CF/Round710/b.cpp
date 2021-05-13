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
    int n, k;
    scanf("%d%d", &n, &k);
    string s;
    cin >> s;
    int answer = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '*') {
            s[i] = 'x';
            answer++;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '*') {
            s[i] = 'x';
            answer++;
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == 'x') {
            if (i + k + 1 < n) {
                int last_star = -1;
                int last_x = -1;
                for (int j = i + 1; j < i + k + 1; j++) {
                    if (s[j] == 'x') {
                        last_x = j;
                        break;
                    }
                    if (s[j] == '*') {
                        last_star = j;
                    }
                }
                if (last_x != -1) {
                    i = last_x - 1;
                } else if (last_star != -1) {
                    s[last_star] = 'x';
                    i = last_star - 1;
                    answer++;
                } else {
                    break;
                }
            } else {
                break;
            }
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
