#include <bits/stdc++.h>

using namespace std;

void go(vector<long long>& a, int n) {
    long long answer = 0;
    /* for (int i = 1; i < n; i += 2) { */
    /*     if (i + 1 < n) { */
    /*         answer += a[i] - max(a[i - 1], a[i + 1]); */
    /*     } */
    /* } */
    for (int start = 0; start < n; start += 2) {
        long long maximum = 0;
        long long prev_min = 1e9 + 10;
        for (int i = start + 2; i < n; i += 2) {
            prev_min = min(prev_min, a[i]);
            maximum = max(maximum, a[i - 1]);
            answer += maximum - max(min2, min1);
        }
    }
    printf("%lld\n", answer);
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    vector<long long> h(n + 1, 0);
    for (int i = 0; i < n; i++) {
        h[i + 1] = h[i] + (i % 2 == 0 ? a[i] : -a[i]);
    }
    go(h, n + 1);
}
