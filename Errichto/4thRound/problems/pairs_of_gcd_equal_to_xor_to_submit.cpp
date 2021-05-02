#include <bits/stdc++.h>

using namespace std;

int MAX = 500001;

long long solve(vector<int> freq) {
    long long answer = 0;
    for (int g = 1; g < MAX; g++) {
        for (int a = g; a + g < MAX; a += g) {
            int b = a + g;
            if ((a ^ b) == g && gcd(a, b) == g) {
                answer += (long long)freq[a] * freq[b];
            }
        }
    }
    return answer;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> freq(MAX);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        freq[x]++;
    }
    printf("%lld\n", solve(freq));
}
