#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int answer = 0;
    while (n > 0) {
        n /= 5;
        answer += n;
    }
    printf("%d\n", answer);
}
