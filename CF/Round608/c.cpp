#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, sx, sy;
    scanf("%d %d %d", &n, &sx, &sy);
    vector<pair<int, int>> pos(n);
    map<pair<int, int>, int> counter;
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        pos[i] = {x, y};
    }
    for (pair<int, int> p : pos) {
        if (p.second == sy) {
            if (p.first > sx) {
                counter[{1, 0}]++;
            } else {
                counter[{-1, 0}]++;
            }
        }
        else if (p.first == sx) {
            if (p.second > sy) {
                counter[{0, 1}]++;
            } else {
                counter[{0, -1}]++;
            }
        } else if(p.second > sy) {
            if (p.first > sx) {
                counter[{0, 1}]++;
                counter[{1, 0}]++;
            } else {
                counter[{0, 1}]++;
                counter[{-1, 0}]++;
            }
        } else if(p.second < sy) {
            if (p.first > sx) {
                counter[{0, -1}]++;
                counter[{1, 0}]++;
            } else {
                counter[{0, -1}]++;
                counter[{-1, 0}]++;
            }
        }
    }
    int maximum = 0;
    pair<int, int> max_coord;
    for (pair<pair<int, int>, int> p : counter) {
        if (p.second > maximum) {
            maximum = p.second;
            max_coord = p.first;
        }
    }
    printf("%d\n", maximum);
    printf("%d %d\n", sx + max_coord.first, sy + max_coord.second);
}
