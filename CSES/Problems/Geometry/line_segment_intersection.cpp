#include <bits/stdc++.h>

using namespace std;

struct Point {
    long long x, y;

    void read() {
        scanf("%lld%lld", &x, &y);
    }

    Point operator-(const Point& other) {
        return Point {x - other.x, y - other.y};
    }
};

struct Vec {
    long long x, y;

    void init(Point a, Point b) {
        x = a.x - b.x;
        y = a.y - b.y;
    }

    long long cross(Vec other) {
        return x * other.y - y * other.x;
    }
};

bool same_side(long long a, long long b) {
    return (a > 0 && b > 0) || (a < 0 && b < 0);
}

void solve() {
    Point a, b, c, d;
    a.read();
    b.read();
    c.read();
    d.read();
    Vec ac, ab, ad, cd, ca, cb;
    ac.init(a, c);
    ab.init(a, b);
    ad.init(a, d);
    cd.init(c, d);
    ca.init(c, a);
    cb.init(c, b);
    long long cross_ab_ac = ab.cross(ac);
    long long cross_ab_ad = ab.cross(ad);
    long long cross_cd_ca = cd.cross(ca);
    long long cross_cd_cb = cd.cross(cb);
    if (same_side(cross_ab_ac, cross_ab_ad) || same_side(cross_cd_ca, cross_cd_cb)) {
        printf("NO\n");
        return;
    }
    if (cross_ab_ac + cross_ab_ad + cross_cd_ca + cross_cd_cb == 0) {
        long long min_y_cd = min(c.y, d.y);
        long long max_y_cd = max(c.y, d.y);
        long long min_y_ab = min(a.y, b.y);
        long long max_y_ab = max(a.y, b.y);
        if (max_y_cd < min_y_ab || max_y_ab < min_y_cd) {
            printf("NO\n");
            return;
        }
        long long min_x_cd = min(c.x, d.x);
        long long max_x_cd = max(c.x, d.x);
        long long min_x_ab = min(a.x, b.x);
        long long max_x_ab = max(a.x, b.x);
        if (max_x_cd < min_x_ab || max_x_ab < min_x_cd) {
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
