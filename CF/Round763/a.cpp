#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, rs, cs, re, ce;
    scanf("%d%d%d%d%d%d", &n, &m, &rs, &cs, &re, &ce);
    int x = rs <= re ? re - rs : (n - rs) * 2 + (rs - re);
    int y = cs <= ce ? ce - cs : (m - cs) * 2 + (cs - ce);
    printf("%d\n", min(x, y));

}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
