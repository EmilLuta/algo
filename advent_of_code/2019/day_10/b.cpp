#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

int main() {
    ifstream input("input.txt");

    if (input.is_open()) {
        string line;
        int i = 0;
        vector<vector<char>> a;
        while (getline(input, line)) {
            int n = line.size();
            a.push_back(vector<char>{});
            for (int j = 0; j < n; j++) {
                a[i].push_back(line[j]);
            }
            i++;
        }
        int n = (int)a.size();
        int m = (int)a[0].size();

        pair<int, int> asteroid = {23, 17};
        int can_see = 0;
        set<pair<int, int>> visited;
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                if (x == asteroid.second && y == asteroid.first || a[y][x] == '.') {
                    continue;
                }
                int dist_x = x - asteroid.second;
                int dist_y = y - asteroid.first;
                int g = abs(__gcd(dist_x, dist_y));
                int g_x = dist_x / g;
                int g_y = dist_y / g;
                if (a[y][x] == '#' && visited.count({g_y, g_x}) == 0) {
                    can_see++;
                    visited.insert({g_y, g_x});
                    /* printf("x = %d, y = %d\n", x, y); */
                    /* printf("Inserting ray %d %d\n", g_x, g_y); */
                }
            }
        }
        printf("%d\n", can_see);
        vector<pair<int, int>> rays;
        for (pair<int, int> p : visited) {
            rays.push_back(p);
        }
        printf("%d\n", rays.size());
        sort(rays.begin(), rays.end(), [](pair<int, int> p1, pair<int, int> p2) {
            return atan2(p1.second, p1.first) > atan2(p2.second, p2.first);
        });
        /* for (int i = 0; i < (int)rays.size(); i++) { */
        /*     printf("%d %d\n", rays[i].first, rays[i].second); */
        /*     sleep(1); */
        /* } */
        int counter = 0;
        for (int i = 0; i < (int)rays.size(); i++) {
            pair<int, int> ray = rays[i];
            int x = asteroid.second + ray.second;
            int y = asteroid.first + ray.first;
            while (x >= 0 && x < m && y >= 0 && y < n) {
                if (a[y][x] == '#') {
                    counter++;
                    printf("Asteroid #%d with coordinates %d %d\n", counter, x, y);
                    a[y][x] = '.';
                    break;
                }

                x += ray.second;
                y += ray.first;
            }
                    }
        return 0;
    }
    printf("Unable to open 'input.txt'.\n");
}
