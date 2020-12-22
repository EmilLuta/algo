#include <bits/stdc++.h>

using namespace std;

void count(char c, int& ones, int& zeros, int& questions, char operation) {
    if (c == '1') {
        if (operation == '+') {
            ones++;
        } else {
            ones--;
        }
    } else if (c == '0') {
        if (operation == '+') {
            zeros++;
        } else {
            zeros--;
        }
    } else {
        if (operation == '+') {
            questions++;
        } else {
            questions--;
        }
    }
}

void solve() {
    int n, k;
    scanf("%d%d", &n, &k);
    int mid = k / 2;
    string s;
    cin >> s;
    vector<char> a(s.begin(), s.end()), b(s.begin(), s.end());
    int ones = 0, zeros = 0, questions = 0;
    for (int i = 0; i < k; i++) {
        count(a[i], ones, zeros, questions, '+');
    }
    if (questions != 0) {
        
    }
    if (ones > mid || zeros > mid) {
        printf("NO\n");
        return;
    }
    for (int i = k; i < n; i++) {
        count(a[i], ones, zeros, questions, '+');
        count(a[i - k], ones, zeros, questions, '-');
        if (ones > mid || zeros > mid) {
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
