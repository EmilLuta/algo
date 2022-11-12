#include <bits/stdc++.h>

using namespace std;

map<pair<int, int>, int> cache;

int pow(int a, int b) {
    if (cache.count({a, b}) != 0) {
        return cache[{a, b}];
    }
    int p = 1;
    for (int i = 0; i < b; i++) {
        p *= a;
    }
    cache[{a, b}] = p;
    return p;
}

map<int, int> exp(long long n) {
    map<int, int> m;
    int i = 2;
    while (n >= i) {
        if (n % i == 0) {
            n /= i;
            m[i]++;
        } else {
            i++;
        }
    }
    return m;
}

long long mine(long long n, long long a, long long b) {
    long long all = n * (n + 1) / 2;
    long long aa = n / a;
    long long div_a = a * (aa * (aa + 1) / 2);
    long long bb = n / b;
    long long div_b = b * (bb * (bb + 1) / 2);
    /* long long div_both; */
    /* if (a % b == 0) { */
    /*     div_both = div_a; */
    /* } else if (b % a == 0) { */
    /*     div_both = div_b; */
    /* } else { */
    map<int, int> exp_a = exp(a);
    /* printf("exp_a = {\n"); */
    /* for (pair<int, int> p : exp_a) { */
    /*     printf("\t%d: %d\n", p.first, p.second); */
    /* } */
    /* printf("}\n"); */
    map<int, int> exp_b = exp(b);
    /* printf("exp_b = {\n"); */
    /* for (pair<int, int> p : exp_b) { */
    /*     printf("\t%d: %d\n", p.first, p.second); */
    /* } */
    /* printf("}\n"); */
    long long d = 1;
    for (pair<int, int> p : exp_a) {
        int val = p.first;
        if (exp_b.count(val) != 0) {
            d *= pow(val, max(p.second, exp_b[val]));
        } else {
            d *= pow(val, p.second);
        }
    }
    for (pair<int, int> p : exp_b) {
        int val = p.first;
        if (exp_a.count(val) == 0) {
            d *= pow(val, p.second);
        }
    }
    long long dd = n / d;
    long long div_both = d * (dd * (dd + 1) / 2);
    return all - div_a - div_b + div_both;
}
long long bf(long long n, long long a, long long b) {
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        if (i % a == 0 || i % b == 0) {
            continue;
        }
        sum += i;
    }
    return sum;
}

int main() {
    int mod = 20;
    while (true) {
        long long n = rand() % mod + 1;
        long long a = rand() % mod + 1;
        long long b = rand() % mod + 1;
        if (mine(n, a, b) != bf(n, a, b)) {
            printf("mine = %lld, bf = %lld, for n = %lld, a = %lld, b = %lld\n", mine(n, a, b), bf(n, a, b), n, a, b);
            /* break; */
        }
    }
    /* long long n = 98 a = 3, b = 10; */
    /* printf("mine = %lld, bf = %lld for (n, a, b) = (%lld, %lld, %lld)\n", mine(n, a, b), bf(n, a, b), n, a, b); */
}
