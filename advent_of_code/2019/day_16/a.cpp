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
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = s[i] - '0';
        }
        for (int i = 0; i < 100; i++) {
            step(a);
        }
        for (int i = 0; i < n; i++) {
            printf("%d", a[i]);
        }
        printf("\n");
        return 0;
    }
    printf("Cannot open 'input.txt'.\n");
}
