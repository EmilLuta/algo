#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e9 + 7;

bool prime[MAX];

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

int main() {
    for (int i = 0; i < 
    long long n, a, b;
    scanf("%lld%lld%lld", &n, &a, &b);
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
    /* printf("d = %lld\n", d); */
    long long dd = n / d;
    long long div_both = d * (dd * (dd + 1) / 2);
    /* } */
        /* if (a % b == 0 || b % a == 0) { */
    /*     div_both *= 2; */
    /* } */
    /* printf("all = %lld, div_a = %lld, div_b = %lld, a = %lld, b = %lld, div_both = %lld\n", all, div_a, div_b, a, b, div_both); */
    printf("%lld\n", all - div_a - div_b + div_both);
}
