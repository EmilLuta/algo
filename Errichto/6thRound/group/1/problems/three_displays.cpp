#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> f(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &f[i]);
    }
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }
    int answer = (1e8 + 5) * 3;
    for (int j = 0; j < n; j++) {
        int best_left = 1e8 + 5;
        for (int i = 0; i < j; i++) {
            if (f[i] < f[j]) {
                best_left = min(best_left, c[i]);
            }
        }
        int best_right = 1e8 + 5;
        for (int k = j + 1; k < n; k++) {
            if (f[j] < f[k]) {
                best_right = min(best_right, c[k]);
            }
        }
        if (best_left <= 1e8 && best_right <= 1e8) {
            answer = min(answer, best_left + c[j] + best_right);
        }
    }
    if (answer > 1e8 * 3 + 1) {
        printf("-1\n");
        return 0;
    }
    printf("%d\n", answer);
}
