#include <bits/stdc++.h>

using namespace std;

// ios::sync_with_stdio(0);
// cin.tie(0);

# define deb_v(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << a[i] << " "; \
    cerr << ")\n";

# define deb(x) cerr << #x << " = " << x << "\n";

void solve(int t) {
    int n, p, k;
    cin >> n >> p >> k;
    p--;
    string s;
    cin >> s;
    int x, y;
    cin >> x >> y;
    long long answer = LLONG_MAX;
    vector<int> pref(k);
    for (int i = 0; i < k; i++) {
        for (int j = i; j < n; j += k) {
            if (s[j] == '0') {
                pref[i]++;
            }
        }
    }
    vector<int> del(k);
    for (int i = 0; i < p; i++) {
        if (s[i] == '0') {
            del[i % k]++;
        }
    }
    for (int i = p; i < n; i++) {
        int i_mod_k = i % k;
        long long current = (i - p) * y + (pref[i_mod_k] - del[i_mod_k]) * x;
        /* printf("shifts = %d; deletes = %d; cost = %lld; total = %d; skipped = %d\n", i - p, pref[i_mod_k] - del[i_mod_k], current, pref[i_mod_k], del[i_mod_k]); */
        answer = min(answer, current);
        if (s[i] == '0') {
            del[i_mod_k]++;
        }
    }
    cout << answer << "\n";
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
