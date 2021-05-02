/*
ID: virgil.1
TASK: ride
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ofstream fout("ride.out");
    ifstream fin("ride.in");

    string comet, group;
    fin >> comet >> group;
    int n_comet = comet.size();
    int n_group = group.size();
    int comet_prod = 1, group_prod = 1;
    for (int i = 0; i < n_comet; i++) {
        comet_prod *= comet[i] - 'A' + 1;
    }
    for (int i = 0; i < n_group; i++) {
        group_prod *= group[i] - 'A' + 1;
    }
    if (comet_prod % 47 == group_prod % 47) {
        fout << "GO\n";
    } else {
        fout << "STAY\n";
    }
}
