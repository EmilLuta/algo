#include <bits/stdc++.h>

using namespace std;

int C_ID = 0;
int S_ID = 0;
int P_ID = 0;

map<string, int > contrib_name_to_id;
map<int, string> contrib_id_to_name;
map<string, int> skill_name_to_id;
map<int, string> skill_id_to_name;
map<string, int> project_name_to_id;
map<int, string> project_id_to_name;


struct Skill {
    int id;
    int level;

    void read(ifstream& f) {
        string name;
        f >> name;
        f >> level;
        if (skill_name_to_id.count(name) == 0) {
            id = S_ID;
            skill_name_to_id[name] = S_ID;
            skill_id_to_name[S_ID] = name;
            S_ID++;
        } else {
            id = skill_name_to_id[name];
        }
    }
};



struct Contrib {
    int id;
    vector<Skill> skills;
    int time = 0;

    void read(ifstream& f) {
        string name;
        f >> name;
        int n;
        f >> n;
        assert(contrib_name_to_id.count(name) == 0) ;
        contrib_name_to_id[name] = C_ID;
        contrib_id_to_name[C_ID] = name;
        this->id = C_ID;
        C_ID++;
        skills.resize(n);
        for (int i = 0; i < n; i++) {
            skills[i].read(f);
        }
    }

    void print() {
        cout << "Contributor #" << id <<" " << contrib_id_to_name[id] << ": {\n";
        for (Skill& s : skills) {
            cout << "\t" << skill_id_to_name[s.id] << " " << s.level << ",\n";
        }
        cout << "}\n";
    }
};

struct Project {
    int id;
    int time;
    int score;
    int deadline;
    vector<Skill> roles;

    void read(ifstream& f) {
        string name;
        f >> name >> time >> score >> deadline;
        assert(project_name_to_id.count(name) == 0);
        id = P_ID;
        project_name_to_id[name] = P_ID;
        project_id_to_name[P_ID] = name;
        P_ID++;
        int n;
        f >> n;
        roles.resize(n);
        for (int i = 0; i < n; i++) {
            roles[i].read(f);
        }
    }

    void print() {
        cout << "Project #" << id << " " << project_id_to_name[id] << ": {\n";
        for (Skill& s : roles) {
            cout << "\t" << skill_id_to_name[s.id] << " " << s.level << ",\n";
        }
        cout << "}\n";
    }

};

struct Assignment {
    int p_id;
    vector<int> c_ids;
};

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Give me a filename as input\n");
        return 0;
    }
    ifstream f(argv[1]);
    if (!f.is_open()) {
        cout << "Couldn't open file " << argv[1] << "!\n";
        return 0;
    }
    string out_file = "out_" + string(argv[1]);
    int C, P;
    f >> C >> P;
    vector<Contrib> contribs(C);
    for (int i = 0; i < C; i++) {
        contribs[i].read(f);
    }
    map<int, vector<pair<int, int>>> skill_to_c_id_level;
    for (Contrib& c : contribs) {
        for (Skill& s : c.skills) {
            skill_to_c_id_level[s.id].push_back({c.id, s.level});
        }
    }
    vector<Project> projects(P);
    for (int i = 0; i < P; i++) {
        projects[i].read(f);
    }

    int max_score = 0;
    while (true) {

        // compute an assignment
        vector<Assignment> out;
        set<int> taken;

        srand(time(NULL));
        vector<Project> random_order_projects(projects.begin(), projects.end());
        random_shuffle(random_order_projects.begin(), random_order_projects.end());
        vector<Contrib> random_order_contribs(contribs.begin(), contribs.end());
        random_shuffle(random_order_contribs.begin(), random_order_contribs.end());

        for (Project& p : random_order_projects) {
            int n = p.roles.size();
            vector<int> folks(n, -1);
            int index = 0;
            for (Skill& p_s : p.roles) {
                for (Contrib& c : random_order_contribs) {
                    if (taken.count(c.id) != 0) {
                        continue;
                    }
                    for (Skill& c_s : c.skills) {
                        if (c_s.id == p_s.id) {
                            if (c_s.level >= p_s.level) {
                                if (c_s.level == p_s.level) {
                                    c_s.level++;
                                }
                                folks[index] = c.id;
                                taken.insert(c.id);
                                break;
                            }
                        }
                    }
                    if (folks[index] != -1) {
                        break;
                    }
                }
                index++;
            }
            bool full = true;
            for (int i = 0; i < n; i++) {
                if (folks[i] == -1) {
                    full = false;
                }
            }
            if (full) {
                out.push_back(Assignment{p.id, folks});
            }
        }

        // score the assignment
        int score = 0;
        for (Assignment& a : out) {
            Project& p = projects[a.p_id];
            if (a.c_ids.size() != p.roles.size()) {
                cout << "Invalid assignment for project #" << p.id << " " << project_id_to_name[p.id] << "\n";
                continue;
            }
            int n = a.c_ids.size();
            map<int, int> max_for_skill;
            for (int i = 0; i < n; i++) {
                Contrib& c = contribs[a.c_ids[i]];
                for (Skill& s : c.skills) {
                    max_for_skill[s.id] = max(max_for_skill[s.id], s.level);
                }
            }
            bool ok = true;
            for (int i = 0; i < n; i++) {
                Contrib& contrib = contribs[a.c_ids[i]];
                for (Skill& s : contrib.skills) {
                    if (s.id == p.roles[i].id) {
                        if (s.level + 1 < p.roles[i].level) {
                            ok = false;
                            cout << "Contributor #" << contrib.id << " " << contrib_id_to_name[contrib.id] << " has level " << s.level << " on skill " << skill_id_to_name[s.id] << " and project requires " << p.roles[i].level << " in skill " << skill_id_to_name[p.roles[i].id] << "; Skipping project #" << p.id << " " << project_id_to_name[p.id] << "\n";
                            break;
                        }
                        if (s.level + 1 == p.roles[i].level) {
                            if (max_for_skill[p.roles[i].id] < p.roles[i].level) {
                                ok = false;
                                cout << "Contributor #" << contrib.id << " " << contrib_id_to_name[contrib.id] << " has level " << s.level << " on skill " << skill_id_to_name[s.id] << " and project requires " << p.roles[i].level << " in skill " << skill_id_to_name[p.roles[i].id] << "; There's no contributor to mentor him either; Skipping project #" << p.id << " " << project_id_to_name[p.id] << "\n";
                                break;
                            }
                            s.level++;
                        }
                        if (s.level == p.roles[i].level) {
                            s.level++;
                        }
                    }
                }
                if (!ok) {
                    break;
                }
            }
            if (ok) {
                int start_time = 0;
                for (int c_id : a.c_ids) {
                    Contrib& c = contribs[c_id];
                    start_time = max(start_time, c.time);
                    c.time += p.time;
                }
                int end = start_time + p.time;
                score += max(0, p.score - max(0, end - p.deadline));
            }
        }

        // get max score
        if (score > max_score) {
            cout << "Found new max_score = " << score << "; prev max_score = " << max_score << "\n";
            max_score = score;

            ofstream to_file(out_file);
            to_file << out.size() << '\n';
            for (Assignment& a : out) {
                to_file << project_id_to_name[a.p_id] << '\n';
                for (int c_id : a.c_ids) {
                    to_file << contrib_id_to_name[c_id] << ' ';
                }
                to_file << '\n';
            }
        }
    }
}
