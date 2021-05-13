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

bool no_is_ok(int no, int x) {
    map<int, int> m;
    m[0] = 0;
    m[1] = 1;
    m[2] = 5;
    m[5] = 2;
    m[8] = 8;
    int last_digit = no % 10;
    int first_digit = no / 10;
    bool found_first = false, found_last = false;
    if (m.count(last_digit) != 0) {
        found_last = true;
    }
    if (m.count(first_digit) != 0) {
        found_first = true;
    }
    if (found_first && found_last) {
        return (m[last_digit] * 10 + m[first_digit]) < x;
    }
    return false;

}

bool is_ok(int curr_h, int curr_m, int h, int m) {
    return no_is_ok(curr_h, h) && no_is_ok(curr_m, m);
}

void solve(int t) {
    int h, m;
    scanf("%d%d", &h, &m);
    string s;
    cin >> s;
    int curr_h = (s[0] - '0') * 10 + s[1] - '0';
    int curr_m = (s[3] - '0') * 10 + s[4] - '0';
    for (int i = 0; i <= h * m; i++) {
        if (is_ok(curr_h, curr_m, m, h)) {
            if (curr_h < 10) {
                printf("0");
            }
            printf("%d:", curr_h);
            if (curr_m < 10) {
                printf("0");
            }
            printf("%d\n", curr_m);
            return;
        }
        curr_m++;
        curr_m %= m;
        if (curr_m == 0) {
            curr_h++;
            curr_h %= h;
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
