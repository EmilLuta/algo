#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int get_next(set<int>& s, int val) {
    auto x = s.upper_bound(val);
    if (x == s.end()) {
        return 1e9;
    }
    return *x;
}

void solve(int t) {
    int n;
    scanf("%d", &n);
    string s;
    cin >> s;
    bool settled = false;
    bool is_o = false;
    vector<int> a(n + 1, 0);
    for (int i = 0; i < n; i++) {
        a[i + 1] = a[i];
        if (s[i] != 'F') {
            if ((settled && s[i] == 'O' && !is_o) || (settled && s[i] == 'X' && is_o)) {
                a[i + 1]++;
                is_o = !is_o;
            }
            if (!settled) {
                settled = true;
                is_o = s[i] == 'O' ? true : false;
            }
        }
    }
    vector<long long> pref(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + a[i];
    }
    set<int> x;
    set<int> o;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'X') {
            x.insert(i);
        }
        if (s[i] == 'O') {
            o.insert(i);
        }
    }
    long long answer = 0;
    long long removed = 0;
    for (int i = 0; i < n; i++) {
        answer += (pref[n] - pref[i + 1]) - removed * (n - i - 1);
        assert(pref[n] - pref[i + 1] - removed * (n - i - 1) >= 0);
        /* printf("%lld\n", answer); */
        /* sleep(1); */
        answer %= MOD;

        if (s[i] == 'O') {
            int next_o = get_next(o, i);
            int next_x = get_next(x, i);
            if (next_x < next_o) {
                removed++;
            }
        } else if (s[i] == 'X') {
            int next_o = get_next(o, i);
            int next_x = get_next(x, i);
            if (next_o < next_x) {
                removed++;
            }

        }
    }
    /* long long answer = 0; */
    /* for (int i = 0; i <= n; i++) { */
    /*     for (int j = i + 1; j <= n; j++) { */
    /*         answer += a[j] - a[i]; */
    /*         answer %= MOD; */
    /*     } */
    /* } */
    /* for (int i = 0; i <= n; i++) { */
    /*     printf("a[%d] = %d\n", i, a[i]); */
    /* } */
    /* for (int i = 0; i < n; i++) { */
        /* for (int j = i */
    /* } */
    printf("Case #%d: %lld\n", t, answer);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
