#include <bits/stdc++.h>

using namespace std;

struct Vec {
    long long x, y;
    void init(pair<long, long> a, pair<long, long> b) {
        x = a.first - b.first;
        y = a.second - b.second;
    }

    long long cross(Vec other) {
        return x * other.y - y * other.x;
    }
};

int main() {
    int n;
    scanf("%d", &n);
    vector<pair<long long, long long>> points(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &points[i].first, &points[i].second);
    }
    long long answer = 0;
    for (int i = 2; i < n; i++) {
        Vec first, second;
        first.init(points[0], points[i - 1]);
        second.init(points[i - 1], points[i]);
        answer += first.cross(second);
    }
    printf("%lld\n", abs(answer));
}
