#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream input("input.txt");

    if (input.is_open()) {
        int x = 25, y = 6;
        int m = x * y;
        string s;
        getline(input, s);
        int n = s.size();
        vector<vector<int>> v(n / m, vector<int>(3, 0));
        for (int i = 0; i < n; i++) {
            int layer = i / m;
            if (s[i] == '0') {
                v[layer][0]++;
            } else if (s[i] == '1') {
                v[layer][1]++;
            } else {
                v[layer][2]++;
            }
        }
        int minimum = INT_MAX;
        int answer;
        for (vector<int> values : v) {
            if (values[0] < minimum) {
                minimum = values[0];
                answer = values[1] * values[2];
            }
        }
        printf("%d\n", answer);
        return 0;
    }
    printf("Unable to open 'input.txt'\n");
}
