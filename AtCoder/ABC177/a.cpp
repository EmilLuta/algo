#include <bits/stdc++.h>

using namespace std;

int main() {
    int d, t, s;
    scanf("%d%d%d", &d, &t, &s);
    int division = d / s;
    int rest = d % s;
    if (division < t || division == t && rest == 0) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
}
