#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    scanf("%lld", &n);
    vector<char> a;
    while (n != 0) {
        if (n % 2 == 0) {
            a.push_back('B');
            n /= 2;
        } else {
            a.push_back('A');
            n--;
        }
    }
    for (int i = (int)a.size() - 1; i >= 0; i--) {
        printf("%c", a[i]);
    }
    printf("\n");
}
