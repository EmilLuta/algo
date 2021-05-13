#include <bits/stdc++.h>

using namespace std;

const int N = 1e9 + 5;

int main() {
    vector<bool> prime(N, true);
    for (int i = 2; i < N; i++) {
        if (prime[i]) {
            for (int j = i * 2; j < N; j += i) {
                prime[j] = false;
            }
        }
    }
    for (int i = N - 1; i >= 0; i--) {
        if (prime[i]) {
            printf("%d\n", i);
            return 0;
        }
    }
}
