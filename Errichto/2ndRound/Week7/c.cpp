#include <bits/stdc++.h>

using namespace std;

long long sq(int a) {
    return (long long) a * a;
}

struct P {
    int x, y, id;
    void read(int _id) {
        scanf("%d%d", &x, &y);
        id = _id;
    }
    P operator -(P b) {
        return P{x - b.x, y - b.y};
    }
    long long operator *(P b) {
        return (long long) x * b.y - (long long) y * b.x;
    }
    long long dot(P b) {
        return (long long) x * b.x + (long long) y * b.y;
    }
    long long dist2() { // norm
        return sq(x) + sq(y);
    }
};

bool points_are_collinear(P a, P b, P c) {
    return (b - a) * (c - a) == 0;
}

long long area(P a, P b, P c) {
    return abs((b - a) * (c - a));
}

/* bool is_in_triangle(P a, P b, P c, P p) { */
/*     return area(a, b, c) == area(a, b, p) + area(a, c, p) + area(b, c, p); */
/* } */

bool same_side(P a, P b, P p1, P p2) {
    long long cp1 = (b - a) * (p1 - a);
    long long cp2 = (b - a) * (p2 - a);
    if (cp1 >= 0 && cp2 >= 0) {
        return true;
    }
    if (cp1 <= 0 && cp2 <= 0) {
        return true;
    }
    return false;
}

bool is_in_triangle(P a, P b, P c, P p) {
    if (same_side(a, b, c, p) && same_side(b, c, a, p) && same_side(a, c, b, p)) {
        return true;
    }
    return false;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<P> points(n);
    for (int i = 0; i < n; i++) {
        points[i].read(i);
    }
    P a = points[0], b = points[1], c = points[2];
    while (points_are_collinear(a, b, c)) {
        assert(c.id < n);
        c = points[c.id + 1];
    }
    assert(!points_are_collinear(a, b, c));
    /* printf("initial points pick: %d %d %d\n", a.id + 1, b.id + 1, c.id + 1); */
    for (int i = 0; i < n; i++) {
        if (i == a.id || i == b.id || i == c.id) {
            continue;
        }
        P p = points[i];
        if (is_in_triangle(a, b, c, p)) {
            /* printf("Point %d belongs to the triangle %d %d %d\n", p.id + 1, a.id + 1, b.id + 1, c.id + 1); */
            if (!points_are_collinear(a, c, p)) {
                b = p;
                /* printf("Updated triangle is %d %d %d\n", a.id + 1, b.id + 1, c.id + 1); */

                continue;
            }
            c = p;
            /* printf("Updated triangle is %d %d %d\n", a.id + 1, b.id + 1, c.id + 1); */

        } else {
            /* printf("Point %d does not belong to the triangle %d %d %d\n", p.id + 1, a.id + 1, b.id + 1, c.id + 1); */
        }
    }
    printf("%d %d %d\n", a.id + 1, b.id + 1, c.id + 1);
}








