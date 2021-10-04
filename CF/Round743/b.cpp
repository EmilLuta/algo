#include <bits/stdc++.h>

using namespace std;

int solve(int t, int n, vector<int>& a, vector<int>& b) {
    /* int n; */
    /* scanf("%d", &n); */
    /* vector<int> a(n), b(n); */
    /* for (int i = 0; i < n; i++) { */
    /*     scanf("%d", &a[i]); */
    /* } */
    /* for (int i = 0; i < n; i++) { */
    /*     scanf("%d", &b[i]); */
    /* } */
    map<int, int> m;
    int index = 0;
    for (int i = 0; i < n; i++) {
        while (a[i] > b[index]) {
            index++;
        }
        m[a[i]] = index;
    }
    int answer = n;
    for (int i = 0; i < n; i++) {
        answer = min(answer, i + m[a[i]]);
        printf("%d %d\n", i, m[a[i]]);
    }
    return answer;
}

int bf(int t, vector<int>& a, vector<int>& b, int n) {
    int answer = n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i] < b[j]) {
                answer = min(answer, i + j);
            }
        }
    }
    return answer;
}

void print_array(string name, vector<int>& a) {
    int n = a.size();
    cout << name;
    printf(" = [");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("]\n");
}

int main() {
    /* int t; */
    /* scanf("%d", &t); */
    /* for (int i = 1; i <= t; i++) { */
    /*     printf("%d\n", solve(t)); */
    /* } */
    while (true) {
        srand(time(NULL));
        int n = rand() % 10;
        vector<int> a;
        vector<int> b;
        for (int i = 1; i <= n * 2; i++) {
            if (i % 2 == 0) {
                b.push_back(i);
            } else {
                a.push_back(i);
            }
        }
        print_array("a", a);
        print_array("b", b);
        random_shuffle(a.begin(), a.end());
        random_shuffle(b.begin(), b.end());
        print_array("a", a);
        print_array("b", b);
        printf("%d %d\n", bf(0, a, b, n * 2), solve(0, n * 2, a, b));
        assert(bf(0, a, b, n * 2) == solve(0, n * 2, a, b));
    }
    /* printf( */
}
