#include <bits/stdc++.h>

using namespace std;

struct Point {
    long long x, y;

    void read() {
        scanf("%lld%lld", &x, &y);
    }
};

int check_point(Point a, vector<Point>& poly) {
    srand(time(NULL));
    int tilt = rand() % 10;
    Point b = {(long long)1e9 + tilt, a.y};
    if (a.x > 0) {
        b.x = -b.x;
    }
    return 0;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<Point> poly(n);
    for (int i = 0; i < n; i++) {
        poly[i].read();
    }
    for (int i = 0; i < m; i++) {
        Point p;
        p.read();
        int point_crosses = check_point(p, poly);
        if (point_crosses == -1) {
            printf("BOUNDARY\n");
        } else if (point_crosses % 2 == 0) {
            printf("OUTSIDE\n");
        } else {
            printf("INSIDE\n");
        }
    }
}
