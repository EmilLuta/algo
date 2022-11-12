#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n;
    scanf("%lld", &n);
    if (n < 4) {
        printf("-1\n");
        return;
    }
    long long maxi = n / 4;
    long long mini = n / 6;
    int r_4 = n % 4;
    int r_6 = n % 6;
    if (!(r_4 == 0 || r_4 == 2)) {
        maxi = -1;
    }
    if (r_6 == 2 || r_6 == 4) {
        mini++;
    } else if (r_6 != 0) {
        mini = -1;
    }
    if (mini == -1 || maxi == -1) {
        printf("-1\n");
        return;
    }
    printf("%lld %lld\n", mini, maxi);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        solve();
        t--;
    }
}
