#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    string answer = "";
    map<char, int> a = {{'A', 0}, {'C', 0}, {'G', 0}, {'T', 0}};
    for (int i = 0; i < n; i++) {
        a[s[i]]++;
        int sum = 0;
        for (pair<int, int> p : a) {
            sum += (p.second == 0 ? 0 : 1);
        }
        if (sum == 4) {
            for (pair<char, int> p : a) {
                a[p.first] = 0;
            }
            answer += s[i];
        }
    }
    for (pair<char, int> p : a) {
        if (p.second == 0) {
            answer += p.first;
            break;
        }
    }
    cout << answer << endl;
}
