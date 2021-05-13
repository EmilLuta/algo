#include <bits/stdc++.h>

using namespace std;

int main() {
    long long a = 576460752303423488;
    int divisions = 0;
    while (a != 2) {
        a /= 2;
        divisions++;
    }
    printf("%d\n", divisions);
    return 0;
}
