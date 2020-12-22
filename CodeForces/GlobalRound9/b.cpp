#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    int matrix[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    for (int i = 1; i < n - 1; i++) {
        if (matrix[i][0] > 3 || matrix[i][m - 1] > 3) {
            printf("NO\n");
            return;
        } else {
            matrix[i][0] = 3;
            matrix[i][m - 1] = 3;
        }
    }
    for (int i = 1; i < m - 1; i++) {
        if (matrix[0][i] > 3 || matrix[n - 1][i] > 3) {
            printf("NO\n");
            return;
        } else {
            matrix[0][i] = 3;
            matrix[n - 1][i] = 3;
        }
    }
    if (matrix[0][0] > 2 || matrix[0][m - 1] > 2 || matrix[n - 1][0] > 2 || matrix[n - 1][m - 1] > 2) {
        printf("NO\n");
        return;
    } else {
        matrix[0][0] = 2;
        matrix[0][m - 1] = 2;
        matrix[n - 1][0] = 2;
        matrix[n - 1][m - 1] = 2;
    }
    for (int r = 1; r < n - 1; r++) {
        for (int c = 1; c < m - 1; c++) {
            if (matrix[r][c] > 4) {
                printf("NO\n");
                return;
            } else {
                matrix[r][c] = 4;
            }
        }
    }
    printf("YES\n");
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            printf("%d ", matrix[r][c]);
        }
        printf("\n");
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
