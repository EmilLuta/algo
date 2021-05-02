#include <bits/stdc++.h>

using namespace std;

map<pair<int, int>, int> bfs(vector<vector<char>> maze, pair<int, int> start) {
    vector<pair<int, int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<pair<int, int>> q{start};
    map<pair<int, int>, int> parents;
    parents[start] = 0;
    int i = 0;
    while (i < (int)q.size()) {
        pair<int, int> current = q[i];
        for (pair<int, int> dir : dirs) {
            pair<int, int> new_dir = {current.first + dir.first, current.second + dir.second};
            if ((parents.count(new_dir) == 0) && (maze[new_dir.second][new_dir.first] != '#')) {
                parents[new_dir] = parents[current] + 1;
                q.push_back(new_dir);
            }
        }
        i++;
    }
    return parents;
}

int main() {
    ifstream input("input.txt");
    if (input.is_open()) {
        vector<vector<char>> maze;
        string s;
        int level = 0;
        pair<int, int> start;
        while (getline(input, s)) {
            maze.push_back(vector<char>{});
            for (int i = 0; i < (int)s.size(); i++) {
                maze[level].push_back(s[i]);
                if (s[i] == '@') {
                    start = {level, i};
                }
            }
            level++;
        }
        map<pair<int, int>, int> p = bfs(maze, start);
        map<pair<int, int>, int> parents;
        for (pair<pair<int, int>, int> key_value : p) {
            pair<int, int> key = key_value.first;
            if (maze[key.second][key.first] != '.') {
                parents[key_value.first] = key_value.second;
                printf("Value %c at (%d, %d) needs %d steps\n", maze[key.second][key.first], key.first, key.second, key_value.second);
            }
        }
        input.close();
        return 0;
    }
    printf("Cannot open file 'input.txt'\n");
}
