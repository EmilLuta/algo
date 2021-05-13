#include <bits/stdc++.h>

using namespace std;

pair<bool, vector<int>> can_turn_color(string s, int n, char c1, char c2) {
    vector<int> out;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == c1) {
            s[i] = c2;
            out.push_back(i + 1);
            if (s[i + 1] == c2) {
                s[i + 1] = c1;
            } else {
                s[i + 1] = c2;
            }
        }
    }
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) {
            return {false, out};
        }
    }
    return {true, out};
}

int main() {
    int n;
    scanf("%d", &n);
    string s;
    cin >> s;
    int black = 0, white = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'B') {
            black++;
        } else {
            white++;
        }
    }
    if (black == 0 || white == 0) {
        printf("0\n");
        return 0;
    }
    pair<bool, vector<int>> out_b = can_turn_color(s, n, 'W', 'B');
    if (out_b.first) {
		printf("%d\n", out_b.second.size());
		for (int i : out_b.second) {
			printf("%d ", i);
		}
		printf("\n");
		return 0;
    }
	pair<bool, vector<int>> out_w = can_turn_color(s, n, 'B', 'W');
    if (out_w.first) {
		printf("%d\n", out_w.second.size());
		for (int i : out_w.second) {
			printf("%d ", i);
		}
		printf("\n");
		return 0;
	}
	printf("-1\n");
}
