#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        string s;
        cin >> s;
        int n = s.size();
        vector<int> out;
        int i = 2;
        while (i < n) {
            if (s[i] == 'e' && s[i - 1] == 'n' && s[i - 2] == 'o') {
                int f = i;
                while (f < n && s[f] == 'e') {
                    f++;
                }
                if (s[f] == 'e' && f == n - 1) {
                    f++;
                }
                int b = i - 2;
                while (i >= 0 && s[b] == 'o') {
                    b--;
                }
                /* printf("For one, i = %d, b = %d, f = %d\n", i, b, f); */
                if (i - 2 - b >= 2 && f - i >= 2) {
                    out.push_back(i);
                    i = f + 1;
                }
                else if (i - 2 - b > f - i) {
                    /* printf("For one, deleting from the front\n"); */
                    /* printf("i = %d, b = %d, f = %d\n", i, b, f); */
                    for (int j = i; j < f; j++) {
                        out.push_back(j + 1);
                    }
                    i = f + 2;
                } else {
                    /* printf("For one, deleting from the back\n"); */
                    for (int j = b + 1; j <= i - 2; j++) {
                        out.push_back(j + 1);
                    }
                    i = f + 2;
                }
                /* printf("Verifying for one %d %d %d\n", i - 2, i - 1, i); */
            } else if (s[i] == 'o' && s[i - 1] == 'w' && s[i - 2] == 't') {
                int f = i;
                while (f < n && s[f] == 'o') {
                    f++;
                }
                if (s[f] == 'o' && f == n - 1) {
                    f++;
                }
                int b = i - 2;
                while (i >= 0 && s[b] == 't') {
                    b--;
                }
                /* printf("Verifying for two %d %d %d\n", i - 2, i - 1, i); */
                if (i - 2 - b >= 2 && f - i >= 2) {
                    out.push_back(i);
                    i = f + 1;
                }
                else if (i - 2 - b >= f - i) {
                    for (int j = i; j < f; j++) {
                        out.push_back(j + 1);
                    }
                    i = f + 2;
                } else {
                    for (int j = b + 1; j <= i - 2; j++) {
                        out.push_back(j + 1);
                    }
                    i = f + 1;
                }
            } else {
                i++;
            }
            /* if (s[i] == 'o' && s[i - 1] == 'w' && s[i - 2] == 't') { */
            /*     int j = i; */
            /*     while (j < n && s[j] == 'o') { */
            /*         out.push_back(j + 1); */
            /*         j++; */
            /*     } */
            /*     i = j; */
            /* } */
            /* if (s[i] == 'e' && s[i - 1] == 'n' && s[i */
        }
        int out_n = out.size();
        printf("%d\n", out_n);
        for (int j = 0; j < (int)out.size(); j++) {
            printf("%d ", out[j]);
        }
        printf("\n");
    }
}
