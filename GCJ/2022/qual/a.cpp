#include <bits/stdc++.h>

using namespace std;

void solve(int T) {
    int R, C;
    scanf("%d%d", &R, &C);
    printf("Case #%d:\n", T);
    for (int i = 0; i < 3; i++) {
        for (int c = 0; c < C; c++) {
            if (c == 0) {
                if (i == 0) {
                    printf("..+");
                } else if (i == 1) {
                    printf("..|");
                } else {
                    printf("+-+");
                }
            } else {
                if (i % 2 == 0) {
                    printf("-+");
                } else {
                    printf(".|");
                }
            }
        }
        printf("\n");
    }
    for (int r = 1; r < R; r++) {
        for (int i = 0; i < 2; i++) {
            for (int c = 0; c < C; c++) {
                if (i == 0) {
                    if (c == 0) {
                        printf("|.|");
                    } else {
                        printf(".|");
                    }
                } else {
                    if (c == 0) {
                        printf("+-+");
                    } else {
                        printf("-+");
                    }
                }
            }
            printf("\n");
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
