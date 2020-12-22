#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    int x = llround(sqrt(n)) + 10;
    int answer = INT_MAX;
    for (int i = 1; i < x; i++) {
        int curr = 0;
        curr += i - 1;
        curr += n / i - 1;
        if (n % i != 0) {
            curr++;
        }
        answer = min(answer, curr);
    }
    printf("%d\n", answer);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
