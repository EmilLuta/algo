#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    for (int tc = 1; tc <= t; tc++) {
        int n, rock, paper, scissors;
        string s;
        scanf("%d %d %d %d", &n, &rock, &paper, &scissors);
        cin >> s;
        vector<char> output (n, 'N');
        int wins = 0, draws = 0, loss = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'R') {
                if (paper > 0) {
                    output[i] = 'P';
                    paper--;
                    wins++;
                }
            } else if (s[i] == 'P') {
                if (scissors > 0) {
                    output[i] = 'S';
                    scissors--;
                    wins++;
                }
            } else {
                if (rock > 0) {
                    output[i] = 'R';
                    rock--;
                    wins++;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (s[i] == 'R') {
                if (rock > 0) {
                    output[i] = 'R';
                    rock--;
                    draws++;
                }
            } else if (s[i] == 'P') {
                if (paper > 0) {
                    output[i] = 'P';
                    paper--;
                    draws++;
                }
            } else {
                if (rock > 0) {
                    output[i] = 'S';
                    scissors--;
                    draws++;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (s[i] == 'R') {
                if (scissors > 0) {
                    output[i] = 'S';
                    scissors--;
                    loss++;
                }
            } else if (s[i] == 'P') {
                if (rock > 0) {
                    output[i] = 'R';
                    rock--;
                    loss++;
                }
            } else {
                if (paper > 0) {
                    output[i] = 'P';
                    paper--;
                    loss++;
                }
            }
        }
        assert(loss + draws + wins == n);
        if (wins / loss
        if (so_far > n / 2) {
            printf("YES\n");
            for (int i = 0; i < n; i++) {
                if (output[i] == 'N') {
                    if (rock > 0) {
                        rock--;
                        printf("R");
                    } else if (paper > 0) {
                        paper--;
                        printf("P");
                    } else {
                        scissors--;
                        printf("S");
                    }
                } else {
                    printf("%c", output[i]);
                }
            }
            printf("\n");
        } else {
            printf("NO\n");
        }
    }
}
