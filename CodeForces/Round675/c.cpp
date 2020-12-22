#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

long long ten[10];

long long get_front(int n, int i, int digit) {
    if (i >= 10) {
        return 0;
    }
    int my_front = n - i - 1;
    int times = my_front * (my_front + 1) / 2;
    return times * ten[i] * digit;
}

long long get_contribution(int n, int i, int digit) {
    long long contribution = 0;
    if (i < 10) {
        int in_front = n - i - 1;
        int times = in_front * (in_front + 1) / 2;
        contribution += ((times * ten[i] * digit) % MOD);
    }
    if (contribution >= MOD) {
        contribution -= MOD;
    }
    
}

long long get_back(n, i, digit) {

}

int main() {
    string s;
    cin >> s;
    int n = s.size();
    reverse(s.begin(), s.end());
    long long x = 1;
    for (int i = 0; i < 10; i++) {
        ten[i] = x;
        x *= 10;
    }
    long long answer = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            continue;
        }
        int digit = s[i] - '0';
        answer += get_contribution(n, i, digit);
        answer %= MOD;
    }
    printf("%lld\n", answer);
}
