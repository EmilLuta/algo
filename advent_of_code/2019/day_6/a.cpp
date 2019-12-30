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
        int output = 0;
        for (pair<string, string> key_value : parents) {
            string key = key_value.first;
            while (key != "COM") {
                key = parents[key];
                output++;
            }
        }
        printf("%d\n", output);
        return 0;
    }
    printf("Cannot open \"input.txt\".\n");

}
