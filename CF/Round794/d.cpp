#include <bits/stdc++.h>

using namespace std;

bool state_ok(pair<int, int> p) {
    return p.first >= 0 && p.second >= 0;
}

bool can_do(int c, int d, string s) {
    int n = s.size();
    set<pair<int, int>> dp_0, dp_1, dp_2;
    dp_0.insert({c, d});
    dp_1.insert({c, d});
    for (int i = 2; i <= n; i++) {
        for (pair<int, int> state : dp_0) {
            dp_2.insert(state);
        }
        if (s[i - 2] == 'A' && s[i - 1] == 'B') {
            for (pair<int, int> state : dp_0) {
                pair<int, int> new_state = {state.first - 1, state.second};
                if (new_state.first == 0 && new_state.second == 0) {
                    return true;
                }
                if (state_ok(new_state)) {
                    dp_2.insert(new_state);
                }
            }
        }
        if (s[i - 2] == 'B' && s[i - 1] == 'A') {
            for (pair<int, int> state : dp_0) {
                pair<int, int> new_state = {state.first, state.second - 1};
                if (new_state.first == 0 && new_state.second == 0) {
                    return true;
                }
                if (state_ok(new_state)) {
                    dp_2.insert(new_state);
                }
            }
        }
        dp_0 = dp_1;
        dp_1 = dp_2;
        dp_2.clear();
        printf("whilst at i = %d\n", i);
        for (pair<int, int> p : dp_1) {
            printf("%d %d\n", p.first, p.second);
        }
        printf("\n");
    }
    return false;
}

void solve() {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    string s;
    cin >> s;
    int n = s.size();
    bool got_combo = can_do(c, d, s);
    if (!got_combo) {
        printf("NO\n");
        return;
    }
    int as = 0;
    int bs = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') {
            as++;
        }
        if (s[i] == 'B') {
            bs++;
        }
    }
    bs -= c;
    as -= c;
    bs -= d;
    as -= d;
    if (as == a && bs == b) {
        printf("YES\n");
        return;
    }
    printf("NO\n");
    /* dp[0].insert(State {a, b, c, d}); */
    /* if (s[0] == 'A') { */
    /*     State state = State {a - 1, b, c, d}; */
    /*     if (state.is_valid()) { */
    /*         dp[1].insert(state); */
    /*     } */
    /* } */
    /* if (s[0] == 'B') { */
    /*     State state = State {a, b - 1, c, d}; */
    /*     if (state.is_valid()) { */
    /*         dp[1].insert(state); */
    /*     } */
    /* } */
    /* for (int i = 1; i <= n; i++) { */
    /*     if (s[i - 1] == 'A') { */
    /*         for (State state : dp[i - 1]) { */
    /*             State new_state = State {state.a - 1, state.b, state.c, state.d}; */
    /*             if (new_state.is_valid()) { */
    /*                 dp[i].insert(new_state); */
    /*             } */
    /*         } */
    /*         if (i > 1 && s[i - 2] == 'B') { */
    /*             for (State state : dp[i - 2]) { */
    /*                 State new_state = State {state.a, state.b, state.c, state.d - 1}; */
    /*                 if (new_state.is_valid()) { */
    /*                     dp[i].insert(new_state); */
    /*                 } */
    /*             } */
    /*         } */

    /*     } */
    /*     if (s[i - 1] == 'B') { */
    /*         for (State state : dp[i - 1]) { */
    /*             State new_state = State {state.a, state.b - 1, state.c, state.d}; */
    /*             if (new_state.is_valid()) { */
    /*                 dp[i].insert(new_state); */
    /*             } */
    /*         } */
    /*         if (i > 1 && s[i - 2] == 'A') { */
    /*             for (State state : dp[i - 2]) { */
    /*                 State new_state = State {state.a, state.b, state.c - 1, state.d}; */
    /*                 if (new_state.is_valid()) { */
    /*                     dp[i].insert(new_state); */
    /*                 } */
    /*             } */
    /*         } */
    /*     } */
    /* } */
    /* for (int i = 0; i <= n; i++) { */
    /*     printf("we can get before index %d with the following states:\n", i); */
    /*     for (State& state : dp[i]) { */
    /*         printf("\t{%d, %d, %d, %d}\n", state.a, state.b, state.c, state.d); */
    /*     } */
    /* } */
    /* for (State state : dp[n]) { */
    /*     if (state.a == 0 && state.b == 0 && state.c == 0 && state.d == 0) { */
    /*         printf("YES\n"); */
    /*         return; */
    /*     } */
    /* } */
    /* printf("NO\n"); */
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        solve();
        t--;
    }
}
