#include <bits/stdc++.h>

using namespace std;

int main() {
    int s, e, c;
    scanf("%d%d%d", &s, &e, &c);
    if (s < e) {
        if (s <= c && c < e) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
        return 0;
    }
    if (s <= c && c <= 23) {
        printf("Yes\n");
        return 0;
    }
    if (c < e) {
        printf("Yes\n");
        return 0;
    }
    printf("No\n");
}
