#include<bits/stdc++.h>

using namespace std;

bool is_good(int number) {
    while (number > 0) {
        int c = number % 10;
        number = number / 10;
        if (c % 2 == 1) {
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        int n;
        scanf("%d", &n);
        for (int j = 0; j <= n; j++) {
            if (is_good(n + j) || is_good(n - j)) {
                cout << "Case #" << i << ": " << j << endl;
                break;
            }
        }
    }
}
