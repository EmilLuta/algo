#include <bits/stdc++.h>

using namespace std;

map<string, int> street_mapping;
int street_id = 0;

struct Intersection {
    unordered_set<int> in;
    vector<unordered_set<int>> cars;

    void set_size(int n) {
        this->cars.resize(n);
    }
};

struct Street {
    int id;
    string name;
    int start;
    int end;
    int dist;

    void read(ifstream& f, vector<Intersection>& intersections) {
        f >> this->start;
        f >> this->end;
        f >> this->name;
        street_mapping[this->name] = street_id;
        this->id = street_id;
        street_id++;
        f >> this->dist;
        intersections[this->end].in.insert(this->id);
    }
};

struct Vehicle {
    int id;
    int n;
    vector<int> streets;
    int current = 0;

    void read(ifstream& f, vector<Intersection>& intersections, vector<Street>& ss, int _id) {
        this->id = _id;
        f >> this->n;
        this->streets.resize(n);
        for (int i = 0; i < this->n; i++) {
            string name;
            f >> name;
            this->streets[i] = street_mapping[name];
        }
        /* intersections[ss[this->streets[0]].start].cars[0].insert(this->id); */
    }
};

struct Out {
    int intersection;
    vector<pair<int, int>> schedules;
    int all;
};

void write_to_file(vector<Out>& out, vector<Street>& streets, string out_file) {
    ofstream w(out_file);
    w << (int)out.size() << "\n";
    for (Out& o : out) {
        w << o.intersection << "\n";
        w << (int)o.schedules.size() << "\n";
        for (pair<int, int> p : o.schedules) {
            w << streets[p.first].name << " " << p.second << "\n";
        }
    }
    w.close();
}

/* long long get_score(vector<Out>& out, vector<Intersection>& intersections, vector<Street>& streets, vector<Vehicle>& vehicles, int D) { */
/*     long long score = 0; */
/*     int V = vehicles.size(); */
/*     int I = intersections.size(); */
/*     for (int v_id = 0; v_id < V; v_id++) { */
/*         intersections[streets[vehicles[v_id].streets[0]].end].cars[0].insert(v_id); */
/*     } */
/*     for (int d = 0; d < D; d++) { */
/*         for (Out& o : out) { */
/*             if ((int)intersections[o.intersection].cars[d].size() != 0 && (int)o.schedules.size() != 0) { */
/*                 for (int car : intersections[o.intersection].cars[d]) { */
/*                     for (pair<int, int> inbound : o.schedules) { */
/*                         if (inbound.first == vehicles[car].streets[vehicles[car].current] */
/*                            ) { */
/*                             if (inbound.second % o.all) */
/*                         } */
/*                     } */
/*                     vehicles[car].streets[vehicles[car].current] */
/*                 } */
/*             } */
/*         } */
/*     } */

/*     for (int i_id = 0; i_id < I; i_id ++) { */
/*         for (int d = 0; d < D; d++) { */
/*             /1* if (d == 0) { *1/ */
/*                 /1* cout << "For intersection " << i_id << " we got the following cars: "; *1/ */
/*                 /1* for (int car : intersections[i_id].cars[0]) { *1/ */
/*                 /1*     cout << car << " "; *1/ */
/*                 /1* } *1/ */
/*                 /1* cout << endl; *1/ */
/*             /1* } *1/ */
/*             intersections[i_id].cars[d].empty(); */
/*         } */
/*     } */
/*     for (int v_id = 0; v_id < V; v_id++) { */
/*         vehicles[v_id].current = 0; */
/*     } */
/*     return score; */
/* } */

int main(int argc, char **argv) {
    if (argc < 2) {
        cout << "Give me filename as input, pls!\n";
        return 0;
    }
    ifstream f(argv[1]);
    if (!f.is_open()) {
        cout << "Couldn't open file" << argv[1] << "!\n";
        return 0;
    }
    string out_file = "out_" + string(argv[1]);
    int D, I, S, V, F;
    f >> D >> I >> S >> V >> F;
    vector<Intersection> intersections(I);
    for (int i = 0; i < I; i++) {
        intersections[i].set_size(D + 1);
    }
    vector<Street> streets(S);
    vector<Vehicle> vehicles(V);
    for (Street& s : streets) {
        s.read(f, intersections);
    }
    for (int i = 0; i < V; i++) {
        vehicles[i].read(f, intersections, streets, i);
    }
    f.close();
    for (int i = 0; i < I; i++) {
        intersections[i].set_size(D + 1);
    }
    vector<int> streets_with_cars(S, 0);
    for (int v_id = 0; v_id < V; v_id++) {
        for (int s_id : vehicles[v_id].streets) {
            streets_with_cars[s_id]++;
        }
    }
    int answer = 0;
    for (int i = 0; i < S; i++) {
        if (streets_with_cars[i] > 0) {
            answer++;
        }
    }
    vector<Out> out;
    for (int i = 0; i < I; i++) {
        Out o = Out{};
        o.intersection = i;
        int total = 0;
        for (int inbound : intersections[i].in) {
            total += streets_with_cars[inbound];
        }
        if (total == 0) {
            continue;
        }
        for (int inbound : intersections[i].in) {
            if (streets_with_cars[inbound] > 0) {
                int x = 1;
                int w = streets_with_cars[inbound];
                /* o.schedules.push_back({streets[inbound].name, min(D, streets_with_cars[inbound] * 7 / total + 1)}); */
                o.schedules.push_back({inbound, min(D, x)});
                /* o.all += 1; */
            }
        }
        if ((int)o.schedules.size() > 0) {
            out.push_back(o);
        }
    }
    /* vector<pair<int, int>> schedule(I); */
    /* for (int i */ 
    /* cout << get_score(out, intersections, streets, vehicles, D) << endl; */
    write_to_file(out, streets, out_file);
}
