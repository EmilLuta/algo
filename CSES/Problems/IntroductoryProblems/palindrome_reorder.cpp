#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    map<char, int> c;
    for (int i = 0; i < n; i++) {
        c[s[i]]++;
    }
    string answer(s);
    int index = 0;
    bool got_odd = false;
    for (pair<char, int> p : c) {
        int got = p.second;
        if (got % 2 != 0) {
            if (got_odd) {
                printf("NO SOLUTION\n");
                return 0;
            }
            got_odd = true;
            answer[n / 2] = p.first;
            got--;
        }
        while (got > 0) {
            answer[index] = p.first;
            answer[n - index - 1] = p.first;
            index++;
            got -= 2;
        }
    }
    cout << answer << "\n";
}
