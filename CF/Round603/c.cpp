#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d\n", &t);
    while (t > 0) {
        t--;
        int n;
        scanf("%d", &n);
        vector<int> o;
        set<int> covered;
        int x;
        int w = n / 2 + 2;
        int y = ((int)sqrt(n) + 1) * 2;
        if (y < w) {
            w = y;
        }
        for (int i = 1; i < w; i++) {
            x = n / i;
            if (covered.count(x) > 0) {
                continue;
            }
            covered.insert(x);
            o.push_back(x);
        }
        for (int i = x - 1; i >= 0; i--) {
            o.push_back(i);
        }
        int h = o.size();
        printf("%d\n", h);
        for (int i = h - 1; i >= 0; i--) {
            printf("%d ", o[i]);
        }
        printf("\n");
    }
}
