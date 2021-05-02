/*
ID: virgil.1
TASK: gift1
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

int get_friend_id(vector<string>& names, string name) {
    for (int i = 0; i < (int)names.size(); i++) {
        if (name == names[i]) {
            return i;
        }
    }
    return -1;
}

int main() {
    ifstream fin("gift1.in");
    ofstream fout("gift1.out");
    int n;
    fin >> n;
    vector<string> names(n);
    vector<int> values(n, 0);
    for (int i = 0; i < n; i++) {
        fin >> names[i];
    }
    for (int i = 0; i < n; i++) {
        string name;
        fin >> name;
        int val;
        fin >> val;
        int my_id = get_friend_id(names, name);
        values[my_id] -= val;
        int fris_n;
        fin >> fris_n;
        if (fris_n == 0) {
            values[my_id] += val;
            continue;
        }
        values[my_id] += val - val / fris_n * fris_n;
        for (int f = 0; f < fris_n; f++) {
            string fri;
            fin >> fri;
            values[get_friend_id(names, fri)] += val / fris_n;
        }
    }
    for (int i = 0; i < n; i++) {
        fout << names[i] << " " << values[i] << "\n";
    }
    return 0;
}
