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

long long gcd(long long a, long long b) {
	if (a == 0) {
        return b;
    }
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    if (a == 0 || b == 0) {
        return 0;
    }
    return a * b / gcd(a, b);
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
        vector<Moon> initial = moons;
        int i = 0;
        vector<int> cycle(3, 0);
        while (true) {
            i++;
            if (i % 1000000 == 0) {
                printf("%d\n", i);
            }
            /* if (i % 1000 == 0) { */
            /*     printf("After %d steps:\n", i); */
            /*     print_moons(moons); */
            /*     int energy = 0; */
            /*     for (int j = 0; j < n; j++) { */
            /*         int pot = 0; */
            /*         int kin = 0; */
            /*         for (int k = 0; k < 3; k++) { */
            /*             pot += abs(moons[j].first[k]); */
            /*             kin += abs(moons[j].second[k]); */
            /*         } */
            /*         /1* printf("moon = %d; pot = %d; kin = %d\n", j, pot, kin); *1/ */
            /*         energy += pot * kin; */
            /*     } */
            /*     printf("Energy after %d steps = %d\n", i, energy); */
            /* } */
            for (int j = 0; j < n; j++) {
                Moon &moon = moons[j];
                for (int k = 0; k < n; k++) {
                    if (k == j) {
                        continue;
                    }
                    Moon &comp_moon = moons[k];
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
            vector<bool> found(3, true);
            for (int k = 0; k < 3; k++) {
                for (int j = 0; j < n; j++) {
                    if (moons[j].second[k] == initial[j].second[k] && moons[j].first[k] == initial[j].first[k]) {
                        found[k] = found[k] & true;
                    } else {
						found[k] = false;
					}
                }
                if (found[k] && cycle[k] == 0) {
                    cycle[k] = i;
                }
            }
            bool good = true;
            for (int j = 0; j < 3; j++) {
                if (cycle[j] == 0) {
                    good = false;
                    break;
                }
            }
            if (good) {
                printf("Cycle of x = %d\n", cycle[0]);
                printf("Cycle of y = %d\n", cycle[1]);
                printf("Cycle of z = %d\n", cycle[2]);
                printf("%lld\n", lcm(lcm((long long)cycle[0], (long long)cycle[1]), (long long)cycle[2]));
                break;
            }
        }
        return 0;
    }
    printf("Unable to open 'input.txt'\n");

}
