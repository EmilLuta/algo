#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    long long answer = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        long long curr = 0;
        long long prev = 0;
        for (int j = i - 1; j >= 0; j--) {
            long long needed = prev / a[j] + 1;
            prev = a[j] * needed;
            curr += needed;
        }
        prev = 0;
        for (int j = i + 1; j < n; j++) {
            long long needed = prev / a[j] + 1;
            prev = a[j] * needed;
            curr += needed;
        }
        answer = min(answer, curr);
    }
    printf("%lld\n", answer);
}
