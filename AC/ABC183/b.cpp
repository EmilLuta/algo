#include <bits/stdc++.h>

using namespace std;

# define deb_v(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << a[i] << " "; \
    cerr << ")\n";

# define deb(x) cerr << #x << " = " << x << "\n";


int main() {
    int sx, sy, gx, gy;
    scanf("%d%d%d%d", &sx, &sy, &gx, &gy);
    int m = min(sx, min(sy, min(gx, gy)));
    sx += m;
    sy += m;
    gx += m;
    gy += m;
    double answer = 0;
    answer = abs((double)(gx - sx) / (sy + gy)) * sx + sx;
    printf("%lf\n", answer);
}
