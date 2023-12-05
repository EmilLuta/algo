#include <bits/stdc++.h>

using namespace std;

map<vector<bool>, long long> cache;

long long find(vector<long long> &a, int start, int end) {
    printf("going with start = %d and end = %d\n", start, end);
    if (start == end) {
        return 0;
    }
    vector<bool> morphed;
    int n = (end - start + 1) / 2;
    for (int i = start; i < start + n; i++) {
        printf("accessing %d and %d\n", i, end - i + start);
        morphed.push_back(a[i] == a[end - i]);
    }
    if (cache.count(morphed) != 0) {
        printf("for a = [");
        for (int i = start; i <= end; i++) {
            printf("%lld ", a[i]);
        }
        printf("] got answer = %lld\n", cache[morphed]);
        return cache[morphed];
    }
    long long answer = 0;
    for (int i = 0; i <= morphed.size(); i++) {
        answer += morphed[i];
    }
    printf("for a = [");
    for (int i = start; i <= end; i++) {
        printf("%lld ", a[i]);
    }
    printf("] got answer = %lld\n", answer);
    return answer + find(a, start + 1, end) + find(a, start, end - 1);

}

int main() {
    int n;
    scanf("%d", &n);
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    long long answer = 0;
    answer += find(a, 0, n - 1);
    printf("%lld\n", answer);
}
