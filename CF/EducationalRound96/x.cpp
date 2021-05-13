#include <bits/stdc++.h>

using namespace std;

int answer = INT_MAX;
vector<vector<int>> REMEMBER;

void go(vector<int> a, vector<vector<int>> remember) {
    int n = a.size();
    /* for (int i = 0; i < n; i++) { */
    /*     printf("%d, ", a[i]); */
    /* } */
    /* printf("\n"); */
    if (n == 1) {
        if (answer > a[0]) {
            answer = a[0];
            REMEMBER = remember;
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int x = (a[i] + a[j] + 1) / 2;
            vector<int> w(a.begin(), a.end());
            w.erase(w.begin() + i);
            w.erase(w.begin() + j - 1);
            w.push_back(x);
            remember.push_back(w);
            go(w, remember);
        }
    }
}

void solve() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }
    vector<vector<int>> remember;
    remember.push_back(a);
    go(a, remember);
    printf("solution:\n");
    for (int i = 0; i < REMEMBER.size(); i++) {
        printf("\t");
        for (int j = 0; j < REMEMBER[i].size(); j++) {
            printf("%d, ", REMEMBER[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
        printf("%d\n", answer);
        answer = INT_MAX;
    }
}
