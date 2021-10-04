#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int get_answer(string s, int l) {
    string new_s = "";
    for (int i = 0; i < l; i++) {
        if (s[i] != 'F') {
            new_s += s[i];
        }
    }
    int n = new_s.size();
    if (n == 0) {
        return 0;
    }
    bool is_o = new_s[0] == 'O' ? true : false;
    int answer = 0;
    for (int i = 1; i < n; i++) {
        if (new_s[i] == 'O') {
            if (is_o) {
                continue;
            } else {
                is_o = !is_o;
                answer++;
            }
        } else {
            if (!is_o) {
                continue;
            } else {
                is_o = !is_o;
                answer++;
            }
        }
    }
    return answer;
}

void solve(int t) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    long long answer = 0;
    for (int i = 0; i < n; i++) {
        string x = "";
        for (int j = i; j < n; j++) {
            x += s[j];
            answer += get_answer(x, (int)x.size());
            answer %= MOD;
        }
    }
    printf("Case #%d: %lld\n", t, answer);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
