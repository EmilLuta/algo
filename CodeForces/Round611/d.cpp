#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    set<int> taken;
    vector<int> trees(n), humans(m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &trees[i]);
        taken.insert(trees[i]);
    }
    set<pair<int, int>> positions;
    for (int i = 0; i < n; i++) {
        if (taken.count(trees[i] - 1) == 0) {
            taken.insert(trees[i] - 1);
            positions.insert({1, trees[i] - 1});
        }
        if (taken.count(trees[i] + 1) == 0) {
            taken.insert(trees[i] + 1);
            positions.insert({1, trees[i] + 1});
        }
    }
    long long s = 0;
    for (int i = 0; i < m; i++) {
        pair<int, int> pos = *positions.begin();
        positions.erase(pos);
        humans[i] = pos.second;
        s += pos.first;
        if (taken.count(pos.second - 1) == 0) {
            taken.insert(pos.second - 1);
            positions.insert({pos.first + 1, pos.second - 1});
        }
        if (taken.count(pos.second + 1) == 0) {
            taken.insert(pos.second + 1);
            positions.insert({pos.first + 1, pos.second + 1});
        }
    }
    printf("%lld\n", s);
    for (int i = 0; i < m; i++) {
        printf("%d ", humans[i]);
    }
    printf("\n");
}
