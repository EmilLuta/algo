#include <bits/stdc++.h>

using namespace std;

long long f(long long t) {
    return t * t + 2 * t + 3;
}

int main() {
    long long t;
    scanf("%lld", &t);
    printf("%lld\n", f(f(f(t) + t) + f(f(t))));
}
