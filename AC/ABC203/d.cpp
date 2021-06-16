#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int a[n][n];
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            scanf("%d", &a[r][c]);
        }
    }
    int h = k * k / 2 + 1;
    vector<int> vals;
    for (int r = 0; r < k; r++) {
        for (int c = 0; c < k; c++) {
            vals.push_back(a[r][c]);
        }
    }
    vector<int> start(vals.begin(), vals.end());
    for (int r = 0; r < n - k; r++) {
        for (int x : vals) {
            printf("%d ", x);
        }
        printf("\n");
        for (int c = 0; c < n - k; c++) {

        }
    }
    int answer = INT_MAX;
    printf("%d\n", answer);
}
