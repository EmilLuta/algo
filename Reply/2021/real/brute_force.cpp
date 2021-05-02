#include <bits/stdc++.h>

using namespace std;

int W, H, B, M, R;

struct Building {
    int x;
    int y;
    int latency;
    int speed;

    void read(ifstream& f) {
        f >> x >> y >> latency >> speed;
    }
};

struct Antenna {
    int range;
    int speed;
    int id;

    void read(ifstream& f, int i) {
        id = i;
        f >> range >> speed;
    }
};

struct Placement {
    int id;
    int x;
    int y;
};

void write_output(char* inp_file, vector<Placement>& placements) {
    string out_file = inp_file;
    out_file.pop_back();
    out_file.pop_back();
    out_file.pop_back();
    out_file = "out_" + out_file + ".out";
    ofstream out(out_file);
    int n = placements.size();
    out << n << "\n";
    for (int i = 0; i < n; i++) {
        out << placements[i].id << " " << placements[i].x << " " << placements[i].y << "\n";
    }
    out.close();
}


int dist(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

pair<long long, bool> get_score(Building& b, Antenna& a, int x, int y) {
    int d = dist(b.x, b.y, x, y);
    if (d <= a.range) {
        return {(long long)b.speed * a.speed - (long long)b.latency * d, true};
    }
    return {0, false};
}

long long compute_score(vector<Placement>& placements, vector<Building>& buildings, vector<Antenna>& antennas) {
    int n = placements.size();
    long long answer = 0;
    int covered = 0;
    for (int i = 0; i < B; i++) {
        long long score = 0;
        bool is_covered;
        for (int j = 0; j < n; j++) {
            pair<long long, bool> p = get_score(buildings[i], antennas[placements[j].id], placements[j].x, placements[j].y);
            score = max(score, p.first);
            is_covered = is_covered || p.second;
        }
        if (is_covered) {
            covered++;
        }
        answer += score;
    }
    if (covered == B) {
        answer += R;
    }
    return answer;
}

int main(int argc, char **argv) {
    srand(time(NULL));
    if (argc != 2) {
        cout << "Give me a filename as input, pls!\n";
        return -1;
    }
    ifstream f(argv[1]);
    if (!f.is_open()) {
        cout << "Couldn't open file " << argv[1] << "!\n";
        return 0;
    }
    f >> W >> H >> B >> M >> R;
    vector<Building> buildings(B);
    for (int i = 0; i < B; i++) {
        buildings[i].read(f);
    }
    vector<Antenna> antennas(M);
    for (int i = 0; i < M; i++) {
        antennas[i].read(f, i);
    }
    f.close();
    /* sort(buildings.begin(), buildings.end(), [](Building& a, Building& b) { return a.speed < b.speed; }); */
    /* sort(antennas.begin(), antennas.end(), [](Antenna& a, Antenna& b) { return a.speed < b.speed; }); */
    vector<Placement> placements;
    int building_i = 0;
    for (int i = 0; i < M; i++) {
        placements.push_back(Placement{i, buildings[building_i].x, buildings[building_i].y});
        building_i++;
    }
    long long old_score = compute_score(placements, buildings, antennas);
    write_output(argv[1], placements);
    cout << "Score is " << old_score << " for " << argv[1] << "\n";
}
