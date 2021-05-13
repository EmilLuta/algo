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
        int so_far = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'R') {
                if (paper > 0) {
                    output[i] = 'P';
                    paper--;
                    so_far++;
                }
            } else if (s[i] == 'P') {
                if (scissors > 0) {
                    output[i] = 'S';
                    scissors--;
                    so_far++;
                }
            } else {
                if (rock > 0) {
                    output[i] = 'R';
                    rock--;
                    so_far++;
                }
            }
        }
        int x = n / 2;
        if (n % 2 == 1) {
            x++;
        }
        if (so_far >= x) {
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
