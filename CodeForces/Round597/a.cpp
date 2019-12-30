#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if (a < b) {
        swap(a, b);
    }
    if (b == 0) {
        return a;
    }
    if (a == b) {
        return a;
    }
    return gcd(a - b, b);
}

int main() {
    int t;
    string buffer;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        int g = gcd(a, b);
        if (g == 1) {
            buffer += "Finite\n";
        } else {
            buffer += "Infinite\n";
        }
    }
    cout << buffer << "\n";
}
