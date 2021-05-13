#include <bits/stdc++.h>

using namespace std;

const int MOD = pow(10, 9) + 7;

int main() {
    string s;
    cin >> s;
    vector<long long> fib(s.size() + 1);
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i < s.size() + 1; i++) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
    }
    int u_section = 0;
    int n_section = 0;
    long long answer = 1;

    for (int i = 0; i <s.size(); i++) {
        if ((s[i] == 'm') || (s[i] == 'w')) {
            printf("%d\n", 0);
            exit(0);
        }
        switch (s[i]) {
            case 'u':
                if (n_section > 1) {
                    answer = (answer * fib[n_section]) % MOD;
                }
                n_section = 0;
                u_section++;
                break;
            case 'n':
                if (u_section > 1) {
                    answer = (answer * fib[u_section]) % MOD;
                }
                u_section = 0;
                n_section++;
                break;
            default:
                if (n_section > 1) {
                    answer = (answer * fib[n_section]) % MOD;
                } else if (u_section > 1) {
                    answer = (answer * fib[u_section]) % MOD;
                }
                u_section = 0;
                n_section = 0;
                break;
        }
    }
    if (u_section > 1) {
        answer = (answer * fib[u_section]) % MOD;
    }
    if (n_section > 1) {
        answer = (answer * fib[n_section]) % MOD;
    }
 
    printf("%lld", answer);
}
