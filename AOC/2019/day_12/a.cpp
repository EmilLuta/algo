#include <bits/stdc++.h>

using namespace std;

typedef pair<vector<int>, vector<int>> Moon;

vector<int> get_moon(string line) {
    int n = (int)line.size();
    string buffer = "";
    vector<int> output;
    for (int i = 0; i < n; i++) {
        if ((line[i] >= '0' && line[i] <= '9') || line[i] == '-') {
            buffer += line[i];
        } else {
            if ((int)buffer.size() > 0) {
                output.push_back(stoi(buffer));
                buffer = "";
            }
        }
    }
    return output;
}

void print_moon(Moon &moon) {
    printf("pos=<x = %d, y = %d, z = %d>, vel=<x = %d, y = %d, z = %d>\n", moon.first[0], moon.first[1], moon.first[2], moon.second[0], moon.second[1], moon.second[2]);
}

void print_moons(vector<Moon> &moons) {
    int n = moons.size();
    for (int i = 0; i < n; i++) {
        print_moon(moons[i]);
    }
}

int main() {
    ifstream input("input.txt");
    if (input.is_open()) {
        vector<Moon> moons(4);
        string line;
        int n = 4;
        for (int i = 0; i < n; i++) {
            getline(input, line);
            vector<int> coords = get_moon(line);
            moons[i] = {coords, {0, 0, 0}};
        }
        for (int i = 0; i <= 1000; i++) {
            printf("After %d steps:\n", i);
            /* print_moons(moons); */
            int energy = 0;
            for (int j = 0; j < n; j++) {
                int pot = 0;
                int kin = 0;
                for (int k = 0; k < 3; k++) {
                    pot += abs(moons[j].first[k]);
                    kin += abs(moons[j].second[k]);
                }
                /* printf("moon = %d; pot = %d; kin = %d\n", j, pot, kin); */
                energy += pot * kin;
            }
            printf("Energy after %d steps = %d\n", i, energy);
            }
            for (int j = 0; j < n; j++) {
                vector<int> vels(3, 0);
                Moon& moon = moons[j];
                for (int k = 0; k < n; k++) {
                    if (k == j) {
                        continue;
                    }
                    Moon comp_moon = moons[k];
                    for (int l = 0; l < 3; l++) {
                        if (comp_moon.first[l] > moon.first[l]) {
                            moon.second[l]++;
                        } else if (comp_moon.first[l] < moon.first[l]) {
                            moon.second[l]--;
                        }
                    }
                }
            }
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < 3; k++) {
                    moons[j].first[k] += moons[j].second[k];
                }
            }
        }
        return 0;
    }
    printf("Unable to open 'input.txt'\n");

}
