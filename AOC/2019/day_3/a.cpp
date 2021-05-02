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

void draw_wire(vector<pair<char, int>> &sequence, map<pair<int, int>, char> &positions, set<pair<int, int>> &intersections, char character) {
    int x = 0;
    int y = 0;
    for (pair<char, int> action : sequence) {
        char direction = action.first;
        int how_far = action.second;
        switch (direction) {
            case 'U':
                while (how_far > 0) {
                    y--;
                    if (positions.count({x, y}) > 0) {
                        if (positions[{x, y}] == character) {
                            printf("Overlapping with %c.\n", character);
                        } else {
                            printf("Intersection at point x = %d y = %d\n", x, y);
                            intersections.insert({x, y});
                        }
                    } else {
                        positions[{x, y}] = character;
                    }
                    how_far--;
                }
                break;
            case 'D':
                while (how_far > 0) {
                    y++;
                    if (positions.count({x, y}) > 0) {
                        if (positions[{x, y}] == character) {
                            printf("Overlapping with %c.\n", character);
                        } else {
                            printf("Intersection at point x = %d y = %d\n", x, y);
                            intersections.insert({x, y});
                        }
                    } else {
                        positions[{x, y}] = character;
                    }
                    how_far--;
                }
                break;
            case 'L':
                while (how_far > 0) {
                    x--;
                    if (positions.count({x, y}) > 0) {
                        if (positions[{x, y}] == character) {
                            printf("Overlapping with %c.\n", character);
                        } else {
                            printf("Intersection at point x = %d y = %d\n", x, y);
                            intersections.insert({x, y});
                        }
                    } else {
                        positions[{x, y}] = character;
                    }
                    how_far--;
                }
                break;
            case 'R':
                while (how_far > 0) {
                    x++;
                    if (positions.count({x, y}) > 0) {
                        if (positions[{x, y}] == character) {
                            printf("Overlapping with %c.\n", character);
                        } else {
                            printf("Intersection at point x = %d y = %d\n", x, y);
                            intersections.insert({x, y});
                        }
                    } else {
                        positions[{x, y}] = character;
                    }
                    how_far--;
                }
                break;
        }
    }

}

int main() {
    ifstream input("input.txt");
    if (input.is_open()) {
        string first_line, second_line;
        getline(input, first_line);
        getline(input, second_line);
        vector<pair<char, int>> first_sequence, second_sequence;
        map<pair<int, int>, char> positions;
        set<pair<int, int>> intersections;
        parse_line(first_sequence, first_line);
        parse_line(second_sequence, second_line);
        draw_wire(first_sequence, positions, intersections, 'A');
        draw_wire(second_sequence, positions, intersections, 'B');
        int min_distance = INT_MAX;
        for (pair<int, int> intersection : intersections) {
            int m_dist = abs(0 - intersection.first) + abs(0 - intersection.second);
            min_distance = min(min_distance, m_dist);
        }
        printf("%d\n", min_distance);
        /* for (int i = -1; i <= 10; i++) { */
        /*     for (int j = -8; j <= 1; j++) { */
        /*         if (i == 0 && j == 0) { */
        /*             printf("o "); */
        /*             continue; */
        /*         } */
        /*         if (positions.count({i, j}) > 0) { */
        /*             if (intersections.count({i, j}) > 0) { */
        /*                 printf("X "); */
        /*             } else { */
        /*                 printf("# "); */
        /*             } */
        /*         } else { */
        /*             printf(". "); */
        /*         } */
        /*     } */
        /*     printf("\n"); */
        /* } */
        return 0;
    }
    printf("Unable to open file input.txt\n");
}
