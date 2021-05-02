/*
ID: virgil.1
TASK: beads
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin("beads.in");
    ofstream fout("beads.out");
    int n;
    string s;
    fin >> n;
    fin >> s;
    s = s + s;
    char curr = s[0];
    int curr_count = 1;
    int prev_count = 0;
    int answer = 0;
    for (int i = 1; i < n * 2; i++) {
        if (s[i] == curr || s[i] == 'w') {
            curr_count++;
        } else {
            /* printf("using curr = %d + prev = %d\n", curr_count, prev_count); */
            answer = max(answer, curr_count + prev_count);
            curr = s[i];
            prev_count = curr_count;
            curr_count = 1;
            for (int j = i - 1; j >= 0 && s[j] == 'w'; j--) {
                curr_count++;
                prev_count--;
            }
        }
    }
    answer = max(answer, prev_count + curr_count);
    answer = min(answer, n);
    fout << answer << "\n";
}
