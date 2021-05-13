#include <bits/stdc++.h>

using namespace std;

int main() {
    int a;
    scanf("%d", &a);
    if (a % 4 == 0) {
        printf("1 A");
    } else if (a % 4 == 1) {
        printf("0 A");
    } else if (a % 4 == 2) {
        printf("1 B");
    } else {
        printf("2 A");
    }
    return 0;
}
