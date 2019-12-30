#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (a < b) {
            swap(a, b);
        }
        int d = a - b;
        int presses = 0;
        for (int option : {5, 2, 1}) {
            presses += d / option;
            d = d % option;
        }
        printf("%d\n", presses);
    }
}
