/*
ID: virgil.1
TASK: friday
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

const int WEEK = 7;
const int MONTH = 12;
const int START_YEAR = 1900;

bool is_leap(int y) {
    return y % 4 == 0 && (y % 400 == 0 || y % 100 != 0);
}

int get_days(int m, int y) {
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m == 1) {
        return days[m] + (is_leap(y) ? 1 : 0);
    }
    return days[m];
}

int main() {
    ifstream fin("friday.in");
    ofstream fout("friday.out");
    int n;
    fin >> n;
    int current = 0;
    vector<int> thirteen(WEEK);
    for (int y = START_YEAR; y < START_YEAR + n; y++) {
        for (int m = 0; m < MONTH; m++) {
            int days = get_days(m, y);
            thirteen[(current - 2 + WEEK) % WEEK]++;
            current = (days + current) % WEEK;
        }
    }
    for (int i = 5; i <= 10; i++) {
        fout << thirteen[i % WEEK] << " ";
    }
    fout << thirteen[4];
    fout << '\n';
}
