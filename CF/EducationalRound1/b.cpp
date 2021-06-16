#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int m;
    scanf("%d", &m);
    for (int q = 0; q < m; q++) {
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        int diff = r - l + 1;
        k %= diff;
        string new_s(s);
        for (int i = 0; i < diff; i++) {
            new_s[l - 1 + (i + k) % diff] = s[l - 1 + i];
        }
        s = new_s;
    }
    cout << s << endl;
}
