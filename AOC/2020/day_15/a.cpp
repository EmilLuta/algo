#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream input("input.txt");
    unordered_map<int, int> m;
    vector<int> a;
    if (input.is_open()) {
        string line;
        while (getline(input, line)) {
            string buffer = "";
            for (int i = 0; i < (int)line.length(); i++) {
                if (line[i] == '\n') {
                    break;
                }
                if (line[i] == ',') {
                    a.push_back(stoi(buffer));
                    buffer = "";
                } else {
                    buffer += line[i];
                }
            }
            if (buffer.length() > 0) {
                a.push_back(stoi(buffer));
            }
        }
    }
    for (int i = 0; i < (int)a.size(); i++) {
        m[a[i]] = i;
        /* printf("%d ", a[i]); */
    }
    /* printf("\n"); */
    int i = a.size();
    int p = 0;
    /* printf("prev = %d, mem = {\n", p); */
    /* for (pair<int, int> x : m) { */
    /*     printf("\t%d: %d,\n", x.first, x.second); */
    /* } */
    /* printf("}\n"); */
    /* printf("i = %d\n", i); */
    while (i < 30000000) {
        int c = p;
        if (m.count(p) == 0) {
            p = 0;
        } else {
            p = i - m[p];
        }
        m[c] = i;
        i++;
        /* printf("i = %d, prev = %d\n", i, p); */
    }
    printf("%d\n", p);
}
