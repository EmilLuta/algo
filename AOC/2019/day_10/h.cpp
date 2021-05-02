#include <bits/stdc++.h>

using namespace std;

int main() {
    int x = 0;
    int y = 0;
    vector<pair<int, int>> slopes;
    for (int i = -5; i < 6; i++) {
        for (int j = -5; j < 6; j++) {
            if (i == x && j == y) {
                continue;
            }
            slopes.push_back({i, j});
        }
    }

    sort(slopes.begin(), slopes.end(), [](pair<int, int> p1, pair<int, int> p2) {
        return atan2(p1.first, p1.second) > atan2(p2.first, p2.second);
    });
    for (auto i : slopes) {
        printf("%d %d\n", i.first, i.second);
    }
}
