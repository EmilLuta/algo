#include<bits/stdc++.h>

using namespace std;

int MOD = 1e9 + 7;

int main() {
    int n;
    scanf("%d", &n);
    if (n < 3) {
        printf("0\n");
        return 0;
    }
    int p = 1;
    for (int i = 1; i <= n; i++) {
        p = (long long)p * i % MOD;
    }
    int power = 1;
    for (int i = 1; i < n; i++) {
        power = (long long)power * 2 % MOD;
    }
    p -= power;
    if (p < 0) {
        p += MOD;
    }
    printf("%d\n", p);
}
