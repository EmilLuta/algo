#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<long long> sizes;
    long long size = 1;
    long long total = 0;
    long long p = 1;
    while (total < 1e18) {
        long long curr = size * (size + 1) / 2;
        sizes.push_back(curr);
        total += curr;
        p *= 2;
        size += p;
    }
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        long long n;
        scanf("%lld", &n);
        int answer = 0;
        int index = 0;
        while (n > 0) {
            n -= sizes[index];
            index++;
            answer++;
        }
        if (n < 0) {
            answer--;
        }
        printf("%d\n", answer);
    }
}
