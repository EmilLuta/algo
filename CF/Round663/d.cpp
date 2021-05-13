#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int matrix[n][m];
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            matrix[i][j] = s[j] - '0';
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }
}
