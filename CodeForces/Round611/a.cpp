#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        int h, m;
        scanf("%d%d", &h, &m);
        int out = 60 - m + (23 - h) * 60;
        printf("%d\n", out);
    }
}
