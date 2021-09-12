#include <bits/stdc++.h>

#include <unistd.h>


using namespace std;

int cache[501][501];

pair<int, int> get_pair(int a, int b) {
    if (a > b) {
        swap(a, b);
    }
    return {a, b};
}

int go(int a, int b, int& c) {
    if (a > b) {
        swap(a, b);
    }
    c++;
    if (a == b) {
        cache[a][b] = 0;
        return 0;
    }
    if (a == 1) {
        cache[a][b] = b - 1;
        return b - 1;
    }
    if (cache[a][b] != 0) {
        return cache[a][b];
    }
    int answer = 1e9;
    for (int i = 1; i < a; i++) {
        pair<int, int> x = get_pair(i, b);
        int left = cache[x.first][x.second] == 0 ? go(i, b, c) : cache[x.first][x.second];
        x = get_pair(a - i, b);
        int right = cache[x.first][x.second] == 0 ? go(a - i, b, c) : cache[x.first][x.second];
        answer = min(answer, left + right);
    }
    for (int i = 1; i < b; i++) {
        pair<int, int> x = get_pair(a, i);
        int left = cache[x.first][x.second] == 0 ? go(a, i, c) : cache[x.first][x.second];
        x = get_pair(a, b - i);
        int right = cache[x.first][x.second] == 0 ? go(a, b - i, c) : cache[x.first][x.second];
        answer = min(answer, left + right);
    }
    cache[a][b] = answer + 1;
    return answer + 1;
}

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    int c = 0;
    printf("%d\n", go(a, b, c));
    /* for (auto p : cache) { */
    /*     printf("(%d %d) => %d\n", p.first.first, p.first.second, p.second); */
    /* } */
    /* printf("cache size = %d\n", (int)cache.size()); */
    /* printf("c = %d\n", c); */
}
