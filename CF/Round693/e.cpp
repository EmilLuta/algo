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

const int HEIGHT = 0, WIDTH = 1, INDEX = 2;

void solve(int t) {
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> a(n);
    vector<vector<int>> vertical(n, vector<int>(3)), horizontal(n, vector<int>(3));
    for (int i = 0; i < n; i += 2) {
        scanf("%d%d", &a[i][HEIGHT], &a[i][WIDTH]);
        vertical[i] = {a[i][HEIGHT], a[i][WIDTH], a[i][INDEX]};
        horizonal[i] = {a[i][WIDTH], a[i][HEIGHT], a[i][INDEX]};
    }
    sort(vertical.begin(), vertical.end());
    sort(horizontal.begin(), horizontal.end());
    vector<int> answer(n);
    /* for (int i = 1; i < n; i++) { */
    /*     if (a[i][HEIGHT] != a[i - 1][HEIGHT] && a[i][WIDTH] > m) { */
    /*         curr_m = m; */
    /*         curr_index = index; */
    /*     } */
    /*     answer[a[i][INDEX] - 1] = curr_index; */
    /*     if (m > a[i][WIDTH]) { */
    /*         m = a[i][WIDTH]; */
    /*         index = a[i][INDEX]; */
    /*     } */
    /* } */
    for (int i = 0; i < n; i++) {
        printf("%d ", answer[i]);
    }
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
