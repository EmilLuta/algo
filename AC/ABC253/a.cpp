#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if ((a >= b && b >= c) || (a <= b && b <= c)) {
        printf("Yes\n");
        return 0;
    }
    printf("No\n");
}
