#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    string s;
    cin >> s;
    int l = 0, r = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') {
            l++;
        } else {
            r++;
        }
    }
    printf("%d\n", r + l + 1);
}
