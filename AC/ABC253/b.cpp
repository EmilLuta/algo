#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<string> a(n);
    int x1 = -1, y1 = -1, x2 = -1, y2 = -1;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'o') {
                if (x1 == -1) {
                    x1 = i;
                    y1 = j;
                } else {
                    x2 = i;
                    y2 = j;
                }
            }
        }
    }
    printf("%d\n", abs(x1 - x2) + abs(y1 - y2));
}
