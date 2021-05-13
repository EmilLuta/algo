#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    vector<int> out(n, -1);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    if (n < 3) {
        printf("0\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
        return 0;
    }
    sort(a.begin(), a.end());
    int f = 0, b = n - 1;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 1) {
            out[i] = a[f];
            f++;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (i % 2 == 0) {
            out[i] = a[b];
            b--;
        }
    }
    int answer = 0;
    for (int i = 1; i < n - 1; i++) {
        if (out[i] < out[i - 1] && out[i] < out[i + 1]) {
            answer++;
        }
    }
    printf("%d\n", answer);
    for (int i = 0; i < n; i++) {
        printf("%d ", out[i]);
    }
    printf("\n");
}
