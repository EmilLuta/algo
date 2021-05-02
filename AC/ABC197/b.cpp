#include <bits/stdc++.h>

using namespace std;

int main() {
    int h, w, x, y;
    scanf("%d%d%d%d", &h, &w, &x, &y);
    x--;
    y--;
    vector<string> a(h);
    for (int i = 0; i < h; i++) {
        cin >> a[i];
    }
    int answer = 1;
    for (int i = x + 1; i < h && a[i][y] != '#'; i++) {
        answer++;
    }
    for (int i = x - 1; i >= 0 && a[i][y] != '#'; i--) {
        answer++;
    }
    for (int i = y + 1; i < w && a[x][i] != '#'; i++) {
        answer++;
    }
    for (int i = y - 1; i >= 0 && a[x][i] != '#'; i--) {
        answer++;
    }
    printf("%d\n", answer);
}
