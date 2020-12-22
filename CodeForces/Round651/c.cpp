#include <bits/stdc++.h>

using namespace std;

pair<int, int> prime_factorization(int n) {
    int i = 2;
    int e = 0, o = 0;
    while (i * i <= n) {
        if (n % i != 0) {
            i++;
        } else {
            n /= i;
            if (i % 2 != 0) {
                o++;
            } else {
                e++;
            }
        }
    }
    if (n > 1) {
        if (n % 2 == 0) {
            e++;
        } else {
            o++;
        }
    }
    return {e, o};
}

void solve() {
    int n;
    scanf("%d", &n);
    if (n == 1) {
        printf("FastestFinger\n");
        return;
    }
    if (n % 2 == 1) {
        printf("Ashishgup\n");
        return;
    }
    pair<int, int> p = prime_factorization(n);
    int e = p.first;
    int o = p.second;
    if ((e > 1 && o == 0) || (e == 1 && o == 1)) {
        printf("FastestFinger\n");
        return;
    }
    printf("Ashishgup\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
