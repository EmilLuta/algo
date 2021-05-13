#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        vector<int> v(3);
        scanf("%d%d%d", &v[0], &v[1], &v[2]);
        sort(v.begin(), v.end());
        if (v[0] + v[1] + 1 < v[2]) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }
}
