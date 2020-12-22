#include <bits/stdc++.h>

using namespace std;

vector<int> decompose(int q) {
    int i = 2;
    vector<int> factors;
    while (i * i <= q) {
        if (q % i == 0) {
            factors.push_back(i);
            q /= i;
        } else {
            i++;
        }
    }
    if (q != 1) {
        factors.push_back(q);
    }
    return factors;
}

void solve() {
    long long p, q;
    scanf("%lld%lld", &p, &q);
    if (p % q != 0) {
        printf("%lld\n", p);
        return;
    }
    int i_q = q;
    vector<int> factors = decompose(q);
    sort(factors.begin(), factors.end());
    vector<int> used;
    int n = factors.size();
    for (int i = 0; i < n; i++) {
        if (p % factors[i] == 0) {
            p /= factors[i];
            q /= factors[i];
            used.push_back(factors[i]);
        }
    }
    while (p % i_q == 0) {
        p /= i_q;
    }
    if (p > i_q) {
        printf("%lld\n", p);
        return;
    }
    int answer = 1;
    used.push_back(p);
    /* sort(used.begin(), used.end()); */
    int m = used.size();
    vector<int> prods(m, 1);
    for (int i = 0; i < m; i++) {
        if (used[i] < i_q) {
            prods[i] *= used[i];
        }
    }
    /* for (int x : used) { */
    /*     printf("x = %d\n", x); */
    /* } */
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (i == j) {
                continue;
            }
            if (prods[i] * used[j] < i_q) {
                prods[i] *= used[j];
            }
        }
    }
    for (int i = 0; i < m; i++) {
        answer = max(answer, prods[i]);
    }
    /* for (int i = m - 1; i >= 0; i--) { */
    /*     int item = used[i]; */
    /*     if ((answer * item) % i_q != 0) { */
    /*         answer *= item; */
    /*     } */
    /*     printf("answer = %d, for item = %d\n", answer, item); */
    /* } */
    printf("%lld\n", answer);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
