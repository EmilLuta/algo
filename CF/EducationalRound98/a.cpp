#include <bits/stdc++.h>

using namespace std;

// ios::sync_with_stdio(0);
// cin.tie(0);

# define deb_v(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << a[i] << " "; \
    cerr << ")\n";

# define deb(x) cerr << #x << " = " << x << "\n";

void solve(int t) {
    int x, y;
    scanf("%d%d", &x, &y);
    int squares = x + y;
    /* if (abs(x - y) <= 1) { */
    /*     printf("%d\n", squares); */
    /*     return; */
    /* } */
    int m = min(x, y);
    int answer = m * 2;
    if (answer < squares) {
        answer++;
    }
    int left = max(0, squares - (answer));
    answer += left * 2;
    printf("%d\n", answer);
}

/* . . . . . */
/* . . . X . */
/* . . . . . */



int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
