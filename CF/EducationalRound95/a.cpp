#include <bits/stdc++.h>

using namespace std;

unsigned long long solve() {
    int x, y, k;
    scanf("%d%d%d", &x, &y, &k);
    unsigned long long sticks = (unsigned long long)k * y + k - 1;
    unsigned long long answer = sticks / (x - 1);
    if (sticks % (x - 1) == 0) {
        return answer + k;
    }
    return answer + 1 + k;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        printf("%llu\n", solve());
    }
}
