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

int palindrome_diff(string s) {
    int n = s.size();
    int c = 0;
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - i - 1]) {
            c++;
        }
    }
    return c;
}

void solve(int t) {
    int n;
    scanf("%d", &n);
    string s;
    cin >> s;
    if (s == "1") {
        printf("DRAW\n");
        return;
    }
    int zeros = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            zeros++;
        }
    }
    int diff = palindrome_diff(s);
    if (diff == 0) {
        if (zeros % 2 == 0 || zeros == 1) {
            printf("BOB\n");
        } else {
            printf("ALICE\n");
        }
        return;
    }
    if (diff == 1) {
        printf("ALICE\n");
        return;
    }
    int bob = diff;
    int alice = zeros - bob;
    /* printf("zeros = %d, bob = %d, alice = %d\n", zeros, bob, alice); */
    if (alice == bob) {
        printf("DRAW\n");
    } else if (alice < bob) {
        printf("ALICE\n");
    } else {
        printf("BOB\n");
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
