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

void fix(const string& s, string& answer, int n, int m) {
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            /* if (i != 0) */
            /*     cout << answer << endl; */
            int start = i - 1;
            while (start >= 0 && start >= i - (2 * m + 2) && s[start] == '0') {
                start--;
            }
            /* printf("i = %d, start = %d\n", i, start); */
            if (start == -1 || start < i - (2 * m + 2)) {
                /* printf("A\n"); */
                for (int j = max(i - m, 0); j < i; j++) {
                    answer[j] = '1';
                }
                continue;
            }
            if ((i - start - 1) % 2 == 1) {
                /* printf("B\n"); */
                for (int j = start; j < start + (i - start) / 2; j++) {
                    answer[j] = '1';
                }
                for (int j = start + (i - start) / 2 + 1; j < i; j++) {
                    answer[j] = '1';
                }
            } else {
                /* printf("C\n"); */
                for (int j = start; j < i; j++) {
                    answer[j] = '1';
                }
            }
        }
    }
    /* cout << "answer = " << answer << endl; */

}

void solve(int t) {
    int n, m;
    scanf("%d%d", &n, &m);
    string s;
    cin >> s;
    string answer(s);
    fix(s, answer, n, m);
    reverse(s.begin(), s.end());
    reverse(answer.begin(), answer.end());
    fix(s, answer, n, m);
    reverse(answer.begin(), answer.end());
    cout << answer << endl;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
