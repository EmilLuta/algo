#include <bits/stdc++.h>

using namespace std;

struct Point {
    long long x, y;

    void read() {
        scanf("%lld%lld", &x, &y);
    }
};

struct Vec {
    long long x, y;

    void from(Point a, Point b) {
        x = b.x - a.x;
        y = b.y - a.y;
    }

    long long cross(Vec other) {
        return x * other.y - y * other.x;
    }
};

void solve() {
    Point a, b, c;
    a.read();
    b.read();
    c.read();
    Vec ab, ac;
    ab.from(a, b);
    ac.from(a, c);
    long long cross = ac.cross(ab);
    if (cross < 0) {
        printf("LEFT\n");
    } else if (cross > 0) {
        printf("RIGHT\n");
    } else {
        printf("TOUCH\n");
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
