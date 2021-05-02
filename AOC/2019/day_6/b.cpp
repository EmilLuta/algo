#include <bits/stdc++.h>

using namespace std;

void get_parent_child(string line, string &parent, string &child) {
    int n = line.size();
    int i = 0;
    for (;; i++) {
        if (line[i] == ')') {
            break;
        }
        parent += line[i];
    }
    i++;
    for (; i < n; i++) {
        child += line[i];
    }
}

int main() {
    ifstream input("input.txt");
    if (input.is_open()) {
        string line;
        map<string, string> parents;
        while (getline(input, line)) {
            string parent = "", child = "";
            get_parent_child(line, parent, child);
            parents[child] = parent;
        }
        if (parents["SAN"] == parents["YOU"]) {
            printf("0\n");
            return 0;
        }
        map<string, int> you_orbit;
        string key = parents["YOU"];
        int so_far = 0;
        while (key != "COM") {
            key = parents[key];
            so_far++;
            you_orbit[key] = so_far;
        }
        map<string, int> santa_orbit;
        key = parents["SAN"];
        so_far = 0;
        while (key != "COM") {
            key = parents[key];
            so_far++;
            santa_orbit[key] = so_far;
        }
        int the_orbit_min = INT_MAX;
        string the_orbit;
        for (pair<string, int> key_value : you_orbit) {
            string current_key = key_value.first;
            if (santa_orbit.find(current_key) != santa_orbit.end()) {
                if (the_orbit_min > you_orbit[current_key]) {
                    the_orbit_min = you_orbit[current_key];
                    the_orbit = current_key;
                }
            }
        }
        printf("%d\n", santa_orbit[the_orbit] + you_orbit[the_orbit]);
        cout << the_orbit << endl;;
        return 0;
    }
    printf("Cannot open \"input.txt\".\n");

}
