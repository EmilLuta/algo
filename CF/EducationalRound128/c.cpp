#include <bits/stdc++.h>

using namespace std;

void min_self(int& me, int other) {
    me = min(me, other);
}

void removal(int& best_zero, int& best_one, int zero, int one) {
    if (max(best_zero, best_one) > max(zero, one)) {
        best_zero = zero;
        best_one = one;
    } else {
        if (one == best_one) {
            min_self(best_zero, zero);
        }
        if (zero == best_zero) {
            min_self(best_one, one);
        }
    }
}

void solve() {
    string a;
    cin >> a;
    int m = a.size();
    int l = 0;
    int r = m - 1;
    while (l < m && a[l] == '0') {
        l++;
    }
    while (r > 0 && a[r] == '0') {
        r--;
    }
    if (l > r) {
        printf("0\n");
        return;
    }
    string s = "";
    for (int i = l; i <= r; i++) {
        s += a[i];
    }
    /* cout << s << endl; */
    int n = s.size();
    int zeros = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            zeros++;
        }
    }
    int best_zero_l = zeros;
    int best_one_l = 0;
    int zero_l = zeros;
    int one_l = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            zero_l--;
        }
        if (s[i] == '1') {
            one_l++;
        }
        removal(best_zero_l, best_one_l, zero_l, one_l);

    }
    int best_zero_r = zeros;
    int best_one_r = 0;
    int zero_r = zeros;
    int one_r = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '0') {
            zero_r--;
        }
        if (s[i] == '1') {
            one_r++;
        }
        removal(best_zero_r, best_one_r, zero_r, one_r);
    }
    printf("zero_l = %d, one_l = %d, answer = %d\n", best_zero_l, best_one_l, max(best_zero_l, best_one_l));
    printf("zero_r = %d, one_r = %d, answer = %d\n", best_zero_r, best_one_r, max(best_zero_r, best_one_r));
    printf("%d\n", min(/*left*/ max(best_zero_l, best_one_l), min(/*right*/ max(best_zero_r, best_one_r), /*merged*/max(best_one_l + best_one_r, zeros - ((zeros - best_zero_l) + (zeros - best_zero_r))))));
    int answer = min(/*left*/ max(best_zero_l, best_one_l), min(/*right*/ max(best_zero_r, best_one_r), /*merged*/max(best_one_l + best_one_r, zeros - ((zeros - best_zero_l) + (zeros - best_zero_r)))));
    printf("%d\n", answer);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        solve();
        t--;
    }
}

