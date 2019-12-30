#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        int n, k;
        scanf("%d %d", &n, &k);
        vector<char> s(n);
        for (int i = 0; i < n; i++) {
            scanf(" %c", &s[i]);
        }
        vector<char> perm(n);
        int j = 0;
        while (k != 1) {
            perm[j] = '(';
            perm[j + 1] = ')';
            j += 2;
            k --;
        }
        int half = n - (n - j) / 2;
        for (int i = j; i < half; i++) {
            perm[i] = '(';
        }
        for (int i = half; i < n; i++) {
            perm[i] = ')';
        }
        /* printf("perm: "); */
        /* for (int i = 0; i < n; i++) { */
            /* printf("%c ", perm[i]); */
        /* } */
        /* printf("\n"); */
        vector<pair<int, int>> output;
        for (int i = 0; i < n; i++) {
            if (s[i] != perm[i]) {
                for (int j = i + 1; j < n; j++) {
                    if (perm[i] == s[j]) {
                        output.push_back({i + 1, j + 1});
                        swap(s[i], s[j]);
                        break;
                    }
                }
            }
        }
        printf("%d\n", (int)output.size());
        for (pair<int, int> p : output) {
            printf("%d %d\n", p.first, p.second);
        }
    }
}
