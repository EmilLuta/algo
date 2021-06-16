#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int answer = 0;
    for (int i = 1; i <= k; i++) {
        answer += i * n;
    }
    for (int i = 1; i <= n; i++) {
        answer += i * 100 * k;
    }
    printf("%d\n", answer);
}
