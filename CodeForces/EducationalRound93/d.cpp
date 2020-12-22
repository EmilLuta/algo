#include <bits/stdc++.h>

using namespace std;

int main() {
    int R, G, B;
    scanf("%d%d%d\n", &R, &G, &B);
    vector<long long> r(R), g(G), b(B);
    for (int i = 0; i < R; i++) {
        scanf("%lld", &r[i]);
    }
    for (int i = 0; i < G; i++) {
        scanf("%lld", &g[i]);
    }
    for (int i = 0; i < B; i++) {
        scanf("%lld", &b[i]);
    }
    sort(r.begin(), r.end());
    sort(g.begin(), g.end());
    sort(b.begin(), b.end());
    int i_r = R - 1, i_b = B - 1, i_g = G - 1;
    long long total = 0;
    while ((i_r >= 0 && i_g >= 0) || (i_r >= 0 && i_b >= 0) || (i_g >= 0 && i_b >= 0)) {
        /* prlong longf("i_r == %d, i_g == %d, i_b == %d\n", i_r, i_g, i_b); */
        long long curr_r = -1, curr_g = -1, curr_b = -1;
        if (i_r >= 0) {
            curr_r = r[i_r];
        }
        if (i_g >= 0) {
            curr_g = g[i_g];
        }
        if (i_b >= 0) {
            curr_b = b[i_b];
        }
        if (curr_r == curr_g && curr_r == curr_b) {
            /* if () { */

            /* } */
            /* if () { */

            /* } */
            /* if () { */

            /* } */
        }
        if (curr_r >= curr_b && curr_g >= curr_b) {
            /* prlong longf("curr_r = %d, curr_g = %d\n", curr_r, curr_g); */
            total += curr_r * curr_g;
            i_r--;
            i_g--;
            continue;
        }
        if (curr_r >= curr_g && curr_b >= curr_g) {
            /* prlong longf("curr_r = %d, curr_b = %d\n", curr_r, curr_b); */
            total += curr_r * curr_b;
            i_r--;
            i_b--;
            continue;
        }
        if (curr_g >= curr_r && curr_b >= curr_r) {
            /* prlong longf("curr_g = %d, curr_b = %d\n", curr_g, curr_b); */
            total += curr_g * curr_b;
            i_g--;
            i_b--;
            continue;
        }
    }
    printf("%lld\n", total);
}
