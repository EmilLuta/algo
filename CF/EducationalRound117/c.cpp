#include <bits/stdc++.h>

using namespace std;

long long sum_up_to(int n) {
    return (long long)n * (n + 1) / 2;
}

long long get_for(int k, int c) {
    if (c <= k) {
        return sum_up_to(c);
    }
    return sum_up_to(k) + (sum_up_to(k - 1) - sum_up_to(max(0, 2 * k - 1 - c)));
}

void solve() {
    int k;
    long long x;
    scanf("%d%lld", &k, &x);
    if (sum_up_to(k) + sum_up_to(k - 1) <= x) {
        printf("%d\n",  2 * k - 1);
        return;
    }
    int start = 0;
    int end = 2 * k - 1;
    int answer = 0;
    bool eq = false;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        long long val = get_for(k, mid);
        if (val <= x) {
            answer = mid;
            eq = (val == x);
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    if (!eq) {
        answer++;
    }
    printf("%d\n", answer);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        solve();
        t--;
    }
}
