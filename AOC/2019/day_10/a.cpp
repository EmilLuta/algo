#include <bits/stdc++.h>

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
        int maximum = 0;
        int max_x = 0;
        int max_y = 0;
        int n = (int)a.size();
        int m = (int)a[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] != '#') {
                    continue;
                }
                pair<int, int> asteroid = {i, j};
                int can_see = 0;
                set<pair<int, int>> visited;
                if (asteroid.second == 0) {
                    continue;
                }
                bool debug = false;
                /* if (j == 5 && i == 8) { */
                    /* debug = true; */
                /* } */
                for (int x = 0; x < m; x++) {
                    for (int y = 0; y < n; y++) {
                        if (x == asteroid.second && y == asteroid.first || a[y][x] == '.') {
                            continue;
                        }
                        int dist_x = asteroid.second - x;
                        int dist_y = asteroid.first - y;
                        int g = abs(__gcd(dist_x, dist_y));
                        int g_x = dist_x / g;
                        int g_y = dist_y / g;
                        if (a[y][x] == '#' && visited.count({g_y, g_x}) > 0 && debug) {
                            printf("---- x = %d y = %d, g_x = %d g_y = %d; dist_x = %d dist_y = %d; g = %d\n", x, y, g_x, g_y, dist_x, dist_y, g);
                        }
                        if (a[y][x] == '#' && visited.count({g_y, g_x}) == 0) {
                            can_see++;
                            if (debug) {
                                printf("Can see x = %d y = %d, 'cause reduced form is x = %d and y = %d\n", x, y, g_x, g_y);
                            }
                            visited.insert({g_y, g_x});
                        }

                    }
                }
                debug = false;
                if (maximum < can_see) {
                    maximum = can_see;
                    max_x = asteroid.second;
                    max_y = asteroid.first;
                }
            }
        }
        printf("Max is: %d at position: %d %d\n", maximum, max_x, max_y);
        return 0;
    }
    printf("Unable to open 'input.txt'.\n");
}
