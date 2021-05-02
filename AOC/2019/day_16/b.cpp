#include <bits/stdc++.h>

using namespace std;

void step(vector<int> &a) {
    int n = a.size();
    vector<int> e(n, 0);
    vector<int> sequence{0, 1, 0, -1};
    int seq_n = sequence.size();
    for (int i = 0; i < n; i++) {
        int k = 0;
        int c = 1;
        e[i] = 0;
        for (int j = 0; j < n; j++) {
            if (c > i) {
                c = 0;
                k++;
            }
            /* printf("for position %d, doing %d += %d * %d\n", i, e[i], a[j], sequence[k % seq_n]); */
            e[i] += a[j] * sequence[k % seq_n];
            c++;
        }
    }
    for (int i = 0; i < n; i++) {
        a[i] = abs(e[i] % 10);
        e[i] = 0;
    }
}

int main() {
    ifstream input("input.txt");
    if (input.is_open()) {
        string s;
        getline(input, s);
        int n = s.size();
        int big_n = n * 10000;
        vector<int> a(big_n);
        for (int i = 0; i < n; i++) {
            a[i] = s[i] - '0';
        }
        for (int i = n; i < big_n; i++) {
            a[i] = a[i % n];
        }
        int offset = 0;
        for (int i = 6; i >= 0; i--) {
            offset += pow(10, i) * a[6 - i];
        }
        vector<int> b(offset);
        /* printf("big_n = %d, offset = %d, last elements are from %d to %d\n", big_n, offset, big_n - offset, big_n); */
        for (int i = offset; i < big_n; i++) {
            /* printf("assinging to %d value at %d\n", i - offset, i); */
            b[i - offset] = a[i];
        }
        for (int i = 0; i < 100; i++) {
            int s = 0;
            for (int j = offset - 1; j >= 0; j--) {
                s += b[j];
                b[j] = s % 10;
            }
        }
        printf("%d%d%d%d%d%d%d%d\n", b[0], b[1], b[2], b[3], b[4], b[5], b[6], b[7]);

        /* for (int i = 0; i < 100; i++) { */
        /*     printf("Finished step %d\n", i); */
        /*     step(a); */
        /* } */
        /* for (int i = 0; i < n; i++) { */
        /*     printf("%d", a[i]); */
        /* } */
        /* printf("\n"); */
        return 0;
    }
    printf("Cannot open 'input.txt'.\n");
}
