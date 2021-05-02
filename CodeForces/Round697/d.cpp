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
    int i_o = n_o, i_t = 0;
    vector<long long> pref_one(n_o + 1, 0), pref_two(n_t + 1, 0); // pref_one[i] = one[0] + ... + one[i - 1]
    for (int i = 0; i < n_o; i++) {
        pref_one[i + 1] = pref_one[i] + ones[i];
    }
    for (int i = 0; i < n_t; i++) {
        pref_two[i + 1] = pref_two[i] + twos[i];
    }
    int answer = n_o + n_t * 2;
    while (i_o >= 0 && i_t <= n_t) {
        if (pref_two[i_t] + pref_one[i_o] >= m) {
            answer = min(answer, i_t * 2 + i_o);
            i_o--;
        } else {
            i_t++;
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
