#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    string s;
    cin >> s;
    int left = n / 2;
    int right = n / 2;
    if (n % 2 == 0) {
        left--;
    }
    while (left >= 0 && right < n && s[left] == s[right] && s[left] == s[n / 2]) {
        left--;
        right++;
    }
    printf("%d\n", right - left - 1);

}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
