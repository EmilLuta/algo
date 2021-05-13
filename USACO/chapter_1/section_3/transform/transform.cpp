/*
ID: virgil.1
TASK: transform
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

void read_matrix(vector<vector<int>>& matrix, int n, ifstream& f) {
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

bool equal(vector<vector<int>>& a, vector<vector<int>>& b, int n) {
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
        for (int i = s; i < n - s - 1; i++) {
            int x = m[s][i];
            m[s][i] = m[n - i - 1][s];
            m[n - i - 1][s] = m[n - s - 1][n - i - 1];
            m[n - s - 1][n - i - 1] = m[i][n - s - 1];
            m[i][n - s - 1] = x;
        }
    }
}

void reflect(vector<vector<int>>& m, int n) {
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n / 2; c++) {
            swap(m[r][c], m[r][n - c - 1]);
        }
    }
}

void print_matrix(vector<vector<int>>& m, int n) {
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            printf("%d ", m[r][c]);
        }
        printf("\n");
    }
    printf("\n");
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
    for (int i = 1; i <= 3; i++) {
        rotate(original, n);
        if (equal(original, trans, n)) {
            fout << i << endl;
            return 0;
        }
    }
    rotate(original, n);
    reflect(original, n);
    if (equal(original, trans, n)) {
        fout << 4 << endl;
        return 0;
    }
    for (int i = 0; i < 3; i++) {
        rotate(original, n);
        if (equal(original, trans, n)) {
            fout << 5 << endl;
            return 0;
        }
    }
    reflect(original, n);
    if (equal(original, trans, n)) {
        fout << 6 << endl;
        return 0;
    }
    fout << 7 << endl;
}
