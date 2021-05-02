/*
ID: virgil.1
TASK: transform
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

void read_matrix(vector<vector<int>>& matrix, int n, ofstream& f) {
    for (int r = 0; r < n; r++) {
        string s;
        f >> s;
        for (int c = 0; c < n; c++) {
            if (s[c] == '@') {
                matrix[r][c] = 1;
            } else {
                matrix[r][c] = 0;
            }
        }
    }
}

void equal(vector<vector<int>>& a, vector<vector<int>>& b, int n) {
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (a[r][c] != b[r][c]) {
                return false;
            }
        }
    }
    return true;
}

void rotate(vector<vector<int>>& m, int n) {
    for (int s = 0; s < n / 2; s++) {
        
    }
     1  2  3  4
     5  6  7  8
     9 10 11 12
    13 14 15 16

    13  9  5  1
    14 10  6  2
    15 11  7  3
    16 12  8  4
}

void reflect(vector<vector<int>>& m, int n) {
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n / 2; c++) {
            swap(m[r][c], m[r][n - c - 1]);
        }
    }
}

int main() {
    ofstream fout("transform.out");
    ifstream fin("transform.in");
    int n;
    fin >> n;
    vector<vector<int>> original(n, vector<int>(n));
    vector<vector<int>> trans(n, vector<int>(n));
    read_matrix(original, n, fin);
    read_matrix(trans, n, fin);
    if (equal(original, trans)) {
        fout << 6 << endl;
        return 0;
    }
    for (int i = 1; i <= 3; i++) {
        rotate(original);
        if (equal(original, trans)) {
            fout << i << endl;
            return 0;
        }
    }
    rotate(original);
    reflect(original);
    if (equal(original, trans)) {
        fout << 4 << endl;
        return 9;
    }
    for (int i = 0; i < 3; i++) {
        if (equal(original, trans)) {
            fout << 5 << endl;
            return 0;
        }
    }
    fout << 7 << endl;
}
