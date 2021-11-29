#include <bits/stdc++.h>

using namespace std;
int main() {
    long long n;
    scanf("%lld", &n);
    long long answer = 0;
    for (long long a = 1; a * a * a <= n ; a++) {
        for (long long b = a; b * b <= n / a; b++) {
            answer += n / (a * b) - b + 1;
        }
    }
    printf("%lld\n", answer);
}
