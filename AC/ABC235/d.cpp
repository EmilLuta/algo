#include <bits/stdc++.h>

using namespace std;

long long pow_10[19];

bool seen[10000001];

int has_digits(long long x) {
    int c = 0;
    while (x > 0) {
        c++;
        x /= 10;
    }
    return c;
}

void go(long long curr, long long mul, long long target, long long ops, long long& answer) {
    /* printf("curr = %lld\n", curr); */
    if (curr > 1e7) {
        return;
    }
    if (seen[curr]) {
        return;
    }
    seen[curr] = true;
    if (curr == target) {
        answer = min(answer, ops);
        return;
    }

    go(curr * mul, mul, target, ops + 1, answer);
    int n = has_digits(curr);
    if (n > 1) {
        int c = 0;
        for (int i = 0; i < n; i++) {
            if (curr % 10 == 0) {
                break;
            }
            curr = (curr % 10) * pow_10[n - 1] + curr / 10;
            c++;
            if (target == curr) {
                answer = min(answer, ops + c);
                return;
            }
            go(curr * mul, mul, target, ops + c + 1, answer);
        }
    }
}

int main() {
    pow_10[0] = 1;
    for (int i = 1; i < 19; i++) {
        pow_10[i] = pow_10[i - 1] * 10;
    }
    long long a, target;
    scanf("%lld%lld", &a, &target);
    long long answer = LLONG_MAX;
    go(1, a, target, 0, answer);
    printf("%lld\n", answer == LLONG_MAX ? -1 : answer);
}
