#include <bits/stdc++.h>

using namespace std;

void get_factors(int q, set<int>& factors) {
    int i = 2;
    while (i * i <= q) {
        while (q % i == 0) {
            factors.insert(i);
            q /= i;
        }
        i++;
    }
    factors.insert(q);
    factors.erase(1);
}

void solve() {
    long long p;
    int q;
    scanf("%lld%d", &p, &q);
    set<int> factors;
    get_factors(q, factors);
    long long answer = 1;
    for (int factor : factors) {
        long long x = p;
        while (x > 0 && p % x == 0) {
            if (x % q != 0) {
                answer = max(answer, x);
                break;
            }
            x /= factor;
        }
        answer = max(answer, x);
    }
    printf("%lld\n", answer);

}

int main() {
    int t;
    scanf("%d", &t);
    while(t > 0) {
        t--;
        solve();
    }
}
