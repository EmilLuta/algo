#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long me, f, n_s, n_a, w_s, w_a;
    scanf("%lld%lld%lld%lld%lld%lld", &me, &f, &n_s, &n_a, &w_s, &w_a);
    if (w_s > w_a) {
        swap(w_s, w_a);
        swap(n_s, n_a);
    }
    long long answer = 0;
    for (int no_me_s = 0; no_me_s <= n_s; no_me_s++) {
        long long w_me_s = no_me_s * w_s;
        if (w_me_s > me) {
            break;
        }
        long long no_me_a = min(n_a, (me - w_me_s) / w_a);
        long long s_left = (n_s - no_me_s);
        long long no_f_s = min(f / w_s, s_left);
        long long no_f_a = min(n_a - no_me_a, (f - no_f_s * w_s) / w_a);
        answer = max(answer, no_me_s + no_me_a + no_f_s + no_f_a);
    }
    printf("%lld\n", answer);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
