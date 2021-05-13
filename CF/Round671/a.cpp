#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    int odd_odd = 0, odd_even = 0, even_even = 0, even_odd = 0;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if ((s[i] - '0') % 2 == 0) {
            if ((i + 1) % 2 == 0) {
                even_even++;
            } else {
                even_odd++;
            }
        } else {
            if ((i + 1) % 2 == 0) {
                odd_even++;
            } else {
                odd_odd++;
            }
        }
    }
    if (n % 2 == 0) {
        if (even_even > 0) {
            printf("2\n");
        } else {
            printf("1\n");
        }
    } else {
        if (odd_odd > 0) {
            printf("1\n");
        } else {
            printf("2\n");
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
