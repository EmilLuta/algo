#include <bits/stdc++.h>

using namespace std;

pair<char, int> get_pair(string action) {
    char direction = action[0];
    string s_squares = "";
    for (int i = 1; i < (int)action.size(); i++) {
        s_squares += action[i];
    }
    int squares = stoi(s_squares);
    return {direction, squares};

}

void parse_line(vector<pair<char, int>> &sequence, string line) {
    int size = line.size();
    string current = "";
    for (int i = 0; i < size; i++) {
        if (line[i] != ',') {
            current += line[i];
        } else {
            sequence.push_back(get_pair(current));
            current = "";
        }
    }
    if ((int)current.size() > 0) {
        sequence.push_back(get_pair(current));
    }
}

void draw_wire(vector<pair<char, int>> &sequence, map<pair<int, int>, int> &positions) {
    int x = 0;
    int y = 0;
    int dist = 0;
    for (pair<char, int> action : sequence) {
        char direction = action.first;
        int how_far = action.second;
        switch (direction) {
            case 'U':
                while (how_far > 0) {
                    y--;
                    dist++;
                    if (positions.count({x, y}) == 0) {
                        positions[{x, y}] = dist;
                    }
                    how_far--;
                }
                break;
            case 'D':
                while (how_far > 0) {
                    y++;
                    dist++;
                    if (positions.count({x, y}) == 0) {
                        positions[{x, y}] = dist;
                    }
                    how_far--;
                }
                break;
            case 'L':
                while (how_far > 0) {
                    x--;
                    dist++;
                    if (positions.count({x, y}) == 0) {
                        positions[{x, y}] = dist;
                    }
                    how_far--;
                }
                break;
            case 'R':
                while (how_far > 0) {
                    x++;
                    dist++;
                    if (positions.count({x, y}) == 0) {
                        positions[{x, y}] = dist;
                    }
                    how_far--;
                }
                break;
        }
    }

}

int get_min_intersection(map<pair<int, int>, int> &f_pos, map<pair<int, int>, int> &s_pos) {
    int min_inter = INT_MAX;
    for (pair<pair<int, int>, int> key_value: f_pos) {
        pair<int, int> key = key_value.first;
        if (s_pos.count(key) > 0) {
            min_inter = min(min_inter, s_pos[key] + f_pos[key]);
        }
    }
    return min_inter;
}

int main() {
    ifstream input("input.txt");
    if (input.is_open()) {
        string first_line, second_line;
        getline(input, first_line);
        getline(input, second_line);
        vector<pair<char, int>> first_sequence, second_sequence;
        map<pair<int, int>, int> f_pos, s_pos;
        set<pair<int, int>> intersections;
        parse_line(first_sequence, first_line);
        parse_line(second_sequence, second_line);
        draw_wire(first_sequence, f_pos);
        draw_wire(second_sequence, s_pos);
        printf("%d\n", get_min_intersection(f_pos, s_pos));
        return 0;
    }
    printf("Unable to open file input.txt\n");
}
