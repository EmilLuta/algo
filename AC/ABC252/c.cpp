#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<vector<int>> pos(10, vector<int>(10, 0));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int l = s.size();
        for (int j = 0; j < l; j++) {
            pos[s[j] - '0'][j]++;
        }
    }
    /* for (int i = 0; i < 10; i++) { */
    /*     printf("we got %d digit on positions:\n", i); */
    /*     for (int j = 0; j < 10; j++) { */
    /*         printf("\t%d: %d\n", i, pos[i][j]); */
    /*     } */
    /*     printf("\n"); */
    /* } */
    int answer = 1e9;
    for (int i = 0; i < 10; i++) {
        int all = n;
        int t = 0;
        while (all > 0) {
            if (pos[i][t % 10] > 0) {
                all--;
                pos[i][t % 10]--;
                /* printf("trying for %d; got rid of 1, left with %d at time %d\n", i, all, t); */
            }
            t++;
        }
        /* printf("can get %d seconds with %d\n", t, i); */
        answer = min(answer, t);
    }
    printf("%d\n", answer - 1);
}
