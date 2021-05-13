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

int divide(int a, int b) {
    int c = 0;
    while (a != 0) {
        a /= b;
        c++;
    }
    return c;
}

void solve(int t) {
    int a, b;
    scanf("%d%d", &a, &b);
    int added = 0;
    if (b == 1) {
        added++;
    }
    int curr_answer = INT_MAX;
    int answer = divide(a, b + added) + added;
    while (curr_answer >= answer) {
        curr_answer = min(curr_answer, answer);
        added++;
        answer = divide(a, b + added) + added;
    }
    printf("%d\n", curr_answer);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
