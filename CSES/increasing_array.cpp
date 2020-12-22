#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    long long answer = 0;
    int prev;
    scanf("%d", &prev);
    for (int i = 1; i < n; i++) {
        int x;
        scanf("%d", &x);
        answer += max(0, prev - x);
        prev = max(prev, x);
    }
    printf("%lld\n", answer);
}
