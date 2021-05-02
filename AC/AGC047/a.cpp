#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    map<pair<int, int>, int> c;
    for (int i = 0; i < n; i++) {
        double x;
        scanf("%lf", &x);
        long long a = llround(x * 1e9);
        int twos = 0;
        while (a % 2 == 0) {
            a /= 2;
            twos++;
        }
        int fives = 0;
        while (a % 5 == 0) {
            a /= 5;
            fives++;
        }
        c[{twos, fives}] += 1;
    }
    long long answer = 0;
    for (pair<pair<int, int>, int> p1 : c) {
        for (pair<pair<int, int>, int> p2 : c) {
            if (p1.first.first + p2.first.first >= 18 && p1.first.second + p2.first.second >= 18) {
                if (p1 < p2) {
                    answer += (long long)p1.second * p2.second;
                } else if (p1 == p2) {
                    answer += (long long)p1.second * (p1.second - 1) / 2;
                }
            }
        }
    }
    printf("%lld\n", answer);
}
