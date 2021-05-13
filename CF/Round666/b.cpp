#include <bits/stdc++.h>

using namespace std;

long long pow(int b, int p) {
    long long answer = 1;
    for (int i = 0; i < p; i++) {
        answer *= b;
    }
    return answer;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<long long> a(n);
    long long s = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        s += a[i];
    }
    long long answer = abs(s - n);
    sort(a.begin(), a.end());
    int b = 2;
    while (true) {
        long long current = 0;
        long long value = 1;
        for (int i = 0; i < n; i++) {
            if (value > llround(1e10)) {
                printf("%lld\n", answer);
                return 0;
            }
            current += abs(value - a[i]);
            value *= b;
        }
        answer = min(answer, current);
        b++;
    }
}
