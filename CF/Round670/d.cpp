#include <bits/stdc++.h>

using namespace std;

long long max(long long a, long long b) {
    if (a > b) {
        return a;
    }
    return b;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    long long c_start = a[0];
    long long b_end = 0;
    vector<long long> diff(n, 0);
    for (int i = 1; i < n; i++) {
        diff[i] = (long long)a[i] - a[i - 1];
        b_end += max(0, diff[i]);
    }

    printf("%lld\n", (b_end + c_start + 1) >> 1);
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int l, r, x;
        scanf("%d%d%d", &l, &r, &x);
        l--;
        r--;
        if (l > 0) {
            b_end -= max(0, diff[l]);
            diff[l] += x;
            b_end += max(0, diff[l]);
        } else {
            c_start = c_start + x;
        }
        if (r < n - 1) {
            b_end -= max(0, diff[r + 1]);
            diff[r + 1] -= x;
            b_end += max(0, diff[r + 1]);
        }
        printf("%lld\n", (b_end + c_start + 1) >> 1);
    }
}
