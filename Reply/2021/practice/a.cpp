#include <bits/stdc++.h>

using namespace std;

map<string, int> skill_map;
map<string, int> company_map;

int skill_c = 0;
int company_c = 0;

struct PM {
    int company;
    int bonus;

    void read(ifstream& f) {
        string s_company;
        f >> s_company;
        if (company_map.count(s_company) == 0) {
            company_map[s_company] = company_c;
            company_c++;
        }
        this->company = company_map[s_company];
        f >> bonus;
    }
}

struct Dev {
    int company;
    int bonus;
    int n_skills;
    set<int> skills;

    void read(ifstream& f) {
        string s_company;
        f >> s_company;
        if (company_map.count(s_company) == 0) {
            company_map[s_company] = company_c;
            company_c++;
        }
        this->company = company_map[s_company];
        f >> bonus >> n_skills;
        for (int i = 0; i < n_skills; i++) {
            string s_skill;
            f >> s_skill;
            if (skill_map.count(s_skill) == 0) {
                skill_map[s_skill] = skill_c;
                skill_c++;
            }
            this->skills.insert(skill_map[s_skill]);
        }
    }
}

int R;
int C;
int D;
int P;

vector<string> matrix;
vector<Dev> developers;

int main(int argc, char** argv) {
    ifstream f(argv[1]);
    f >> R >> C;
    matrix.resize(R);
    for (int r = 0; r < R; r++) {
        f >> matrix[r];
    }
    f >> D;
    developers.resize(D);
    for (int i = 0; i < D; i++) {
        developers[i].read(f);
    }
    f >> P;
    f.close();
}
