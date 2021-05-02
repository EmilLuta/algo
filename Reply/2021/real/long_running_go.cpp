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
    if (argc != 3) {
        cout << "Give me a filename as input, pls!\n";
        return -1;
    }
    int mod = atoi(argv[2]);
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
    vector<Placement> placements;
    set<pair<int, int>> taken;
    vector<int> left;
    for (int i = 0; i < M; i++) {
        left.push_back(i);
    }
    while (true) {
        if ((taken.size() == W * H) || ((int)left.size() == 0)) {
            break;
        }
        int x = rand() % W;
        int y = rand() % H;
        while (taken.count({x, y}) != 0) {
            x = rand() % W;
            y = rand() % H;
        }
        taken.insert({x, y});
        int pick = rand() % (int)left.size();
        placements.push_back(Placement{left[pick], x, y});
        swap(left[pick], left[(int)left.size() - 1]);
        left.pop_back();
    }
    long long old_score = compute_score(placements, buildings, antennas);
    long long initial_score = old_score;
    int n = placements.size();
    int count = 0;
    while (true) {
        int id = rand() % n;
        int c_x = placements[id].x;
        int c_y = placements[id].y;
        int r_x = rand() % 10;
        int s_x = rand() % 2;
        int r_y = rand() % 10;
        int s_y = rand() % 2;
        if (s_x == 0) {
            c_x += r_x;
            c_x = min(c_x, W - 1);
        } else {
            c_x -= r_x;
            c_x = max(c_x, 0);
        }
        if (s_y == 0) {
            c_y += r_y;
            c_y = min(c_y, H - 1);
        } else {
            c_y -= r_y;
            c_y = max(c_y, 0);
        }
        if (taken.count({c_x, c_y}) != 0) {
            continue;
        }
        int prev_x = placements[id].x;
        int prev_y = placements[id].y;
        placements[id].x = c_x;
        placements[id].y = c_y;
        int new_score = compute_score(placements, buildings, antennas);
        if (new_score >= old_score) {
            old_score = new_score;
            taken.erase({prev_x, prev_y});
            taken.insert({c_x, c_y});
        } else {
            placements[id].x = prev_x;
            placements[id].y = prev_y;
        }
        count++;
        if (count % mod == 0) {
            write_output(argv[1], placements);
            cout << "Started with " << initial_score << " got to " << old_score << "\n";
        }
    }
    write_output(argv[1], placements);
    cout << "Score is " << old_score << " for " << argv[1] << "\n";
}
