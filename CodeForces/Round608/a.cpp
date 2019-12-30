#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c, d, e, f;
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
    int out = 0;
    if (e > f) {
        int x = min(a, d);
        d -= x;
        out += x * e;
        out += f * min(min(b, c), d);
    } else {
        int x = min(min(b, c), d);
        d -= x;
        out += x * f;
        out += e * min(a, d);
    }
    printf("%d\n", out);
}
