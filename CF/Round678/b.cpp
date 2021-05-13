#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 5;

void solve(vector<bool>& primes) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i < MAX; i++) {
        if (primes[i]) {
            continue;
        }
        long long x = i * (n - 1) + 1;
        if (primes[x]) {
            for (int r = 0; r < n; r++) {
                for (int c = 0; c < n; c++) {
                    if (r == c) {
                        printf("1 ");
                    } else {
                        printf("%d ", i);
                    }
                }
                printf("\n");
            }
            return;
        }
    }
}

int main() {
    vector<bool> primes(MAX, true);
    primes[0] = false;
    for (int i = 2; i < MAX; i++) {
        if (primes[i]) {
            for (int j = i + i; j < MAX; j += i) {
                primes[j] = false;
            }
        }
    }
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve(primes);
    }
}
