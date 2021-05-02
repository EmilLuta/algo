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
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    vector<int> ones, twos;
    long long total = 0;
    for (int i = 0; i < n; i++) {
        if (b[i] == 1) {
            ones.push_back(a[i]);
        } else {
            twos.push_back(a[i]);
        }
        total += a[i];
    }
    if (total < m) {
        printf("-1\n");
        return;
    }
    sort(ones.begin(), ones.end());
    reverse(ones.begin(), ones.end());
    sort(twos.begin(), twos.end());
    reverse(twos.begin(), twos.end());
    int n_o = ones.size();
    int n_t = twos.size();
    int i_o = 0, i_t = 0;
    int freed = 0;
    while (freed < m && i_o < n_o && i_t < n_t) {
        if (freed + ones[i_o] >= m) {
            i_o++;
            printf("%d\n", i_t * 2 + i_o);
            return;
        }
        if (freed + twos[i_t] >= m) {
            i_t++;
            printf("%d\n", i_t * 2 + i_o);
            return;
        }
        if (i_o < n_o - 1 && ones[i_o] + ones[i_o + 1] + freed >= m) {
            i_o += 2;
            printf("%d\n", i_t * 2 + i_o);
            return;
        }
        if (freed + ones[i_o] + twos[i_t] >= m) {
            i_t++;
            i_o++;
            printf("%d\n", i_t * 2 + i_o);
            return;
        }
        if (ones[i_o] >= twos[i_t]) {
            freed += ones[i_o];
            i_o++;
        } else if (i_o < n_o - 1 && ones[i_o] + ones[i_o + 1] >= twos[i_t]) {
            freed += ones[i_o];
            freed += ones[i_o + 1];
            i_o += 2;
        } else {
            freed += twos[i_t];
            i_t++;
        }
    }
    if (freed >= m) {
        printf("%d\n", i_t * 2 + i_o);
        return;
    }
    if (i_o == n_o) {
        while (i_t < n_t && freed < m) {
            freed += twos[i_t];
            i_t++;
        }
        if (freed >= m) {
            printf("%d\n", n_o + 2 * i_t);
        }
        return;
    }
    if (i_t == n_t) {
        while (i_o < n_o && freed < m) {
            freed += ones[i_o];
            i_o++;
        }
        if (freed >= m) {
            printf("%d\n", n_t * 2 + i_o);
        }
        return;
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
