#include <bits/stdc++.h>

#include <unistd.h>


using namespace std;

pair<int, int> get_pair(int a, int b) {
    if (a > b) {
        swap(a, b);
    }
    return {a, b};
}

int go(map<pair<int, int>, int>& cache, int a, int b, int& c) {
    if (a > b) {
        swap(a, b);
    }
    c++;
    if (a == b) {
        cache[{a, b}] = 0;
        return 0;
    }
    if (a == 1) {
        cache[{a, b}] = b - 1;
        return b - 1;
    }
    if (cache.count({a, b}) != 0) {
        return cache[{a, b}];
    }
    int answer = 1e9;
    for (int i = 1; i < a; i++) {
        int left = cache.count(get_pair(i, b)) == 0 ? go(cache, i, b, c) : cache[get_pair(i, b)];
        int right = cache.count(get_pair(a - i, b)) == 0 ? go(cache, a - i, b, c) : cache[get_pair(a - i, b)];
        answer = min(answer, left + right);
    }
    for (int i = 1; i < b; i++) {
        int left = cache.count(get_pair(a, i)) == 0 ? go(cache, a, i, c) : cache[get_pair(a, i)];
        int right = cache.count(get_pair(a, b - i)) == 0 ? go(cache, a, b - i, c) : cache[get_pair(a, b - i)];
        answer = min(answer, left + right);
    }
    cache[{a, b}] = answer + 1;
    return answer + 1;
}

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    map<pair<int, int>, int> cache;
    int c = 0;
    printf("%d\n", go(cache, a, b, c));
    /* for (auto p : cache) { */
    /*     printf("(%d %d) => %d\n", p.first.first, p.first.second, p.second); */
    /* } */
    printf("cache size = %d\n", (int)cache.size());
    printf("c = %d\n", c);
}
