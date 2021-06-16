#include <bits/stdc++.h>

using namespace std;

struct P {
    int id, x, y;
    long long operator *(const P& other) {
        return (long long)x * other.y - (long long)other.x * y;
    }

    long long norm() {
        return x * x + y * y;
    }
    __int128 diff(P& other) {
        P me = *this;
        return __int128(me * other) * (me * other) * norm() * other.norm();
    }
    bool is_first() const {
        return make_pair(x, y) > make_pair(0, 0);
    }

    bool operator <(const P& other) const {
        if (is_first() != other.is_first()) {
            return is_first();
        }
        P me = *this;
        return me * other < 0;
    }
};

int main() {
    int n;
    scanf("%d", &n);
    vector<P> points(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        points[i] = P{i + 1, x, y};
    }
    sort(points.begin(), points.end());
    /* for (int i = 0; i < n; i++) { */
    /*     printf("%f\n", vals[i].val); */
    /* } */
    __int128 m = (__int128)9223372036854775807ll * 9223372036854775807ll;
    pair<int, int> answer = {1, 2};
    for (int i = 0; i < n; i++) {
        /* printf("diff = %Lf\n", vals[i] - vals[i + 1]); */
        /* printf("ddiff = %Lf\n\n", diff); */
        __int128 diff;
        if (i == n - 1) {
            diff = points[i].diff(points[0]);
        } else {
            diff = points[i].diff(points[i + 1]);
        }
        if (diff < m) {
            answer = {points[i].id, points[i + 1].id};
            m = diff;
        }
    }
    printf("%d %d\n", answer.first, answer.second);
}
