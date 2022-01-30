#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int answer = 0;
    while (n > 0) {
        int d = n % 10;
        answer += d + 10 * d + 100 * d;
        n /= 10;
    }
    printf("%d\n", answer);
}
