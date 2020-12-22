#include <bits/stdc++.h>

using namespace std;

# define deb_v(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << a[i] << " "; \
    cerr << ")\n";

# define deb(x) cerr << #x << " = " << x << "\n";

int minimum = INT_MAX;

void compute(vector<int>& a, const int& n) {
    long long no = 0;
    int used = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            used++;
        } else {
            no = (10 * no) + a[i];
        }
    }
    if (used >= minimum || used == n) {
        return;
    }
    if (no % 3 == 0) {
        minimum = min(minimum, used);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (a[i] != 0) {
            int tmp = a[i];
            a[i] = 0;
            compute(a, n);
            a[i] = tmp;
        }
    }
}

int main() {
    long long x;
    scanf("%lld", &x);
    vector<int> a;
    while (x > 0) {
        a.push_back(x % 10);
        x /= 10;
    }
    reverse(a.begin(), a.end());
    compute(a, (int)a.size());
    if (minimum == INT_MAX) {
        printf("-1\n");
        return 0;
    }
    printf("%d\n", minimum);
}
