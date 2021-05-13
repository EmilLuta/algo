/*
ID: virgil.1
TASK: namenum
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream d("dict.txt");
    set<string> names;
    while (!d.eof()) {
        string name;
        d >> name;
        names.insert(name);
    }
    ofstream fout("namenum.out");
    ifstream fin("namenum.in");
    map<char, vector<char>> m = {
        {'2', {'A', 'B', 'C'}},
        {'3', {'D', 'E', 'F'}},
        {'4', {'G', 'H', 'I'}},
        {'5', {'J', 'K', 'L'}},
        {'6', {'M', 'N', 'O'}},
        {'7', {'P', 'R', 'S'}},
        {'8', {'T', 'U', 'V'}},
        {'9', {'W', 'X', 'Y'}}
    };
    string s;
    fin >> s;
    vector<string> prev = {""};
    vector<string> curr;
    for (int i = 0; i < (int)s.size(); i++) {
        for (string pref : prev) {
            for (char c : m[s[i]]) {
                bool ok = false;
                for (string name : names) {
                    bool works = true;
                    for (int j = 0; j < (int)pref.size(); j++) {
                        if (pref[j] != name[j]) {
                            works = false;
                        }
                    }
                    if (works) {
                        ok = true;
                        break;
                    }
                }
                if (ok) {
                    curr.push_back(pref + c);
                }
            }
        }
        prev = curr;
        curr = {};
    }
    sort(prev.begin(), prev.end());
    bool found = false;
    for (string name : prev) {
        if (names.count(name)) {
            fout << name << "\n";
            found = true;
        }
    }
    if (!found) {
        fout << "NONE\n";
    }
}
