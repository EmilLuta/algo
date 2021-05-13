#include <bits/stdc++.h>

using namespace std;

void get_primes(long long n, map<long long, long long>& a) {
    long long i = 2;
    while (i * i <= n) {
        if (n % i != 0) {
            i++;
        } else {
            n /= i;
            a[i]++;
        }
    }
    if (n > 1) {
        a[n]++;
    }
}

int main() {
    long long k;
    scanf("%lld", &k);
    vector<int> powers(10, 1);
    int index = 0;
    long long p = 1;
    while (p < k) {
        p /= powers[index];
        powers[index]++;
        p *= powers[index];
        index = (index + 1) % 10;
    }
    string word = "codeforces", answer;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < powers[i]; j++) {
            answer += word[i];
        }
    }
    cout << answer << '\n';
}
