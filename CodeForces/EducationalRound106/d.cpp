#include <bits/stdc++.h>

using namespace std;

// ios::sync_with_stdio(0);
// cin.tie(0);

# define deb_v(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << item << " "; \
    cerr << ")\n";

# define deb(x) cerr << #x << " = " << x << "\n";

# define deb_v_p(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << "(" << item.first << ", " << item.second << ") "; \
    cerr << ")\n";

int const N = 2e7 + 7;
int prime_divisor[N];

vector<int> get_divisors(int n) {
    vector<int> divisors;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i * i != n) {
                divisors.push_back(n / i);
            }
        }
    }
    return divisors;
}

int get_exponents(int n) {
    int c = 0;
    while (n != 1) {
        int p = prime_divisor[n];
        bool got_one = false;
        while (n % p == 0) {
            got_one = true;
            n /= p;
        }
        c++;
    }
    return c;
}

void solve(int t) {
    int c, d, x;
    scanf("%d%d%d", &c, &d, &x);
    int answer = 0;
    vector<int> divs = get_divisors(x);
    for (int g : divs) {
        long long w = (long long)x + (long long) d * g;
        if (w % c != 0) {
            continue;
        }
        long long l = w / c;
        if (l % g != 0) {
            continue;
        }
        long long r = l / g;
        /* printf("lcm = %d, gcd = %d, r = %d, exponents size = %d\n", l, g, r, (int)(get_exponents(r)).size()); */
        answer += 1 << get_exponents(r);
    }
    printf("%d\n", answer);
}

int main() {
    vector<int> is_prime(N, true);
    for (int i = 2; i < N; i++) {
        if (is_prime[i]) {
            prime_divisor[i] = i;
            for (int j = i * 2; j < N; j += i) {
                prime_divisor[j] = i;
                is_prime[j] = false;
            }
        }
    }
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
