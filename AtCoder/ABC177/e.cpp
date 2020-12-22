#include <bits/stdc++.h>

using namespace std;

int LIMIT = 1e6 + 10;

map<int, int> decompose(int x) {
    int d = 2;
    map<int, int> answer;
    while (x != 1) {
        if (x % d == 0) {
            answer[d]++;
            x /= d;
        } else {
            d++;
        }
    }
    return answer;
}

bool is_pairwise(vector<map<int, int>>& a, vector<int>& b) {
    map<int, int> single;
    for (int i = 0; i < (int)a.size(); i++) {
        /* printf("b[%d] = %d, decomposed in:\n", i, b[i]); */
        for (auto k_v : a[i]) {
            single[k_v.first]++;
            /* printf("%d: %d\n", k_v.first, k_v.second); */
        }
        /* printf("\n\n"); */
    }
    for (auto k_v : single) {
        /* printf("%d: %d\n", k_v.first, k_v.second); */
        if (k_v.second > 1) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<bool> sieve(LIMIT, true);
    for (int i = 2; i < LIMIT; i++) {
        if (sieve[i]) {
            for (int j = i + i; j < LIMIT; j += i) {
                sieve[j] = false;
            }
        }
    }
    int n;
    scanf("%d", &n);
    vector<map<int, int>> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        b[i] = x;
        if (sieve[x]) {
            a[i] = {{x, 1}};
        } else {
            a[i] = decompose(x);
        }
    }
    if (is_pairwise(a, b)) {
        printf("pairwise coprime\n");
    } else {
        int g = b[0];
        for (int i = 1; i < n; i++) {
            g = __gcd(g, b[i]);
        }
        if (g == 1) {
            printf("setwise coprime\n");
        } else {
            printf("not coprime\n");
        }
    }
}
