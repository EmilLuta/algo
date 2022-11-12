#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    vector<int> t(n);
    map<string, int> grade;
    int val = 0;
    int index = -1;
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> t[i];
        if (grade.count(s[i]) == 0) {
            grade[s[i]] = t[i];
            if (t[i] > val) {
                val = t[i];
                index = i + 1;
            }
        }
    }
    cout << index << endl;
}
